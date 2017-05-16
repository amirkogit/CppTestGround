#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <memory>
#include <algorithm>

using namespace std;

// lightweight structure holding 3D coordinate values to represent vertex coordinates
struct Point3D {
    double x;
    double y;
    double z;
};

typedef vector<Point3D> PointList;

// basic class to represent any 3D model that includes information like name, id and vertex information
class Model3D {
public:
    Model3D() {}

    Model3D(string name, int id) {
        m_name = name;
        m_id = id;
        m_transparency = 0.5;
    }

    ~Model3D() {}

    string getName() { return m_name; }
    int getID() { return m_id; }
    float getTransparency() { return m_transparency; }

    void setName(const string& name) { m_name = name; }
    void setID(int id) { m_id = id; }
    void setTransparency(float transparency) { m_transparency = transparency; }

    void setVertexes(const PointList& vertex_data) {
        m_vertexes = vertex_data;
    }

    const PointList& getVertexes() {
        return m_vertexes;
    }

private:
    string m_name;
    int m_id;
    float m_transparency;
    PointList m_vertexes;
};


// helper function to print the contents of a collection (containing shared pointers)
template <typename Coll>
void printAllItemsContainingSharedPointers(const string& msg, const Coll& coll)
{
    std::cout << msg.c_str() << std::endl;
    for (const auto& elem : coll) {
        std::cout << ' ' << elem->getName().c_str() << ": "
            << elem->getTransparency() << std::endl;
    }
}

template <typename Coll>
void printAllItemsContainingReferenceWrappers(const string& msg, const Coll& coll)
{
    std::cout << msg.c_str() << std::endl;
    for (const auto& elem : coll) {
        std::cout << ' ' << elem.get().getName().c_str() << ": "
            << elem.get().getTransparency() << std::endl;
    }
}

void testUsingSharedPointers()
{
    cout << "\n >>> Testing sharing of objects in multiple containers(using shared pointers).\n";

    typedef shared_ptr<Model3D> ModelPtr;

    set<ModelPtr> master_list;
    deque<ModelPtr> filtered_list;

    // insert model objects into collections
    master_list = { ModelPtr(new Model3D("car",1)),
        ModelPtr(new Model3D("wall",2)),
        ModelPtr(new Model3D("tree",3)),
        ModelPtr(new Model3D("house",4)) };

    filtered_list = { ModelPtr(new Model3D("person",5)),
        ModelPtr(new Model3D("bridge",6)),
        ModelPtr(new Model3D("lamp poll",7)) };

    // master_list contains items from filtered_list also
    master_list.insert(filtered_list.begin(), filtered_list.end());

    // print the contents of both collections
    printAllItemsContainingSharedPointers("master list", master_list);
    printAllItemsContainingSharedPointers("filtered list", filtered_list);
    cout << endl;

    cout << "After some manipulation in collection objects... \n";

    // change the transparency of filtered list to 0.7
    for_each(filtered_list.begin(), filtered_list.end(),
        [](shared_ptr<Model3D>& elem) {
        elem->setTransparency(0.7);
    });

    // set the name of first item in filtered list to people
    filtered_list[0]->setName("people");

    // replace occurence of 'bridge' with 'draw_bridge'
    //for_each(filtered_list.begin(), filtered_list.end(),)
    auto pos = find_if(filtered_list.begin(), filtered_list.end(),
        [](shared_ptr<Model3D> elem) {
        return elem->getName() == "bridge";
    });

    if (pos != std::end(filtered_list)) {
        (*pos).get()->setName("draw_bridge");
    }

    // print the contents of both collections
    printAllItemsContainingSharedPointers("master list", master_list);
    printAllItemsContainingSharedPointers("filtered list", filtered_list);
    cout << endl;
}

void testUsingReferenceWrappers()
{
    cout << "\n>>> Testing sharing of objects in multiple containers(using reference wrappers).\n";

    typedef std::reference_wrapper<Model3D> ModelRefWrapper;

    vector<ModelRefWrapper> master_list;
    deque<ModelRefWrapper> filtered_list;

    // insert model objects into collections
    Model3D car("car", 1);
    Model3D wall("wall", 2);
    Model3D tree("tree", 3);
    Model3D house("house", 4);
    Model3D bridge("bridge", 5);
    Model3D poll("lamp poll", 6);

    filtered_list.push_back(bridge);
    filtered_list.push_back(poll);

    master_list.push_back(car);
    master_list.push_back(wall);
    master_list.push_back(tree);
    master_list.push_back(house);
    master_list.insert(master_list.end(), filtered_list.begin(), filtered_list.end());

    // print the contents of both collections
    printAllItemsContainingReferenceWrappers("master list", master_list);
    printAllItemsContainingReferenceWrappers("filtered list", filtered_list);
    cout << endl;

    cout << "After some manipulation in collection objects... \n";

    // change the transparency of filtered list to 0.7
    for_each(filtered_list.begin(), filtered_list.end(),
        [](Model3D& elem) {
        elem.setTransparency(0.7);
    });

    // replace occurence of 'bridge' with 'draw_bridge'
    //for_each(filtered_list.begin(), filtered_list.end(),)
    auto pos = find_if(filtered_list.begin(), filtered_list.end(),
        [](Model3D& elem) {
        return elem.getName() == "bridge";
    });

    if (pos != std::end(filtered_list)) {
        (*pos).get().setName("draw_bridge");
    }

    // print the contents of both collections
    printAllItemsContainingReferenceWrappers("master list", master_list);
    printAllItemsContainingReferenceWrappers("filtered list", filtered_list);
    cout << endl;
}

// main program entry
int main()
{
    testUsingSharedPointers();
    
    testUsingReferenceWrappers();

    getchar();
    return 0;
}