#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct Attribute {
	string name;
	string value;
};
typedef struct Attribute Attribute;

struct Tag {
	string name;
	vector<Tag> children;
	vector<Attribute> attr;
	Tag* parent;
};
typedef struct Tag Tag;

vector<Attribute> getAttributes(stringstream &ss) {
	vector<Attribute> attributes;

	bool nameflag = true;
	bool attrflag = false;
	string name = "";
	string attr = "";
	char ch;

	// Get attributes
	while (!ss.eof()) {
		ss >> ch;
		if (ch == '>') break;

		if (nameflag) {
			if (ch != ' ' && ch != '=') name.push_back(ch);
			else nameflag = false;
			continue;
		}

		if (ch == '"' && !attrflag) {
			attrflag = true;
			continue;
		}

		if (attrflag) {
			if (ch != ' ' && ch != '"') attr.push_back(ch);
			else {
				attrflag = false; nameflag = true;
				attributes.push_back(Attribute{ name, attr });
				name = ""; attr = "";
			}
			continue;
		}
	}

	return attributes;
}

string findAttr(Tag *root, string atr) {
	bool found = false;

	vector<Attribute>::iterator it;
	for (it = root->attr.begin(); it < root->attr.end(); it++) {
		if (it->name == atr) { return it->value; };
	}
	return "";
}

Tag* FindTag(Tag *root, string name) {
	vector<Tag>::iterator it;
	for (it = root->children.begin(); it < root->children.end(); it++) {
		if ((*it).name == name) {
			return &(*it);
		}
	}
	return NULL;
}

int main() {
	int N, Q;
	stringstream ss;
	string line;
	string out;

	Tag *root = new Tag{ "root", vector<Tag>(), vector<Attribute>(),NULL };
	Tag *current = root;
	Tag *newTag;
	vector<Attribute> newAttrs;

	getline(cin, line);
	ss.str(line);
	ss >> N >> Q;
	ss.str("");
	ss.clear();

	while (N--) {
		getline(cin, line);

		if (line.find("</") == -1) {                         //opening tag 
			string tagname;
			char ch;
			ss.str("");
			ss.clear();
			ss.str(line);
			// Get name of tag
			ss >> ch >> tagname;

			int tag_idx = tagname.find(">");
			if (tag_idx != -1) tagname = tagname.substr(0, tag_idx);

			// Get attributes
			newAttrs = getAttributes(ss);

			newTag = new Tag{ tagname, vector<Tag>(), newAttrs, current };
			current->children.push_back(Tag{ tagname, vector<Tag>(), newAttrs, current });
			current = &(current->children.back());
		}
		else {                                              //closing tag
			current = current->parent;
		}
	}

	// Do queries
	while (Q--) {
		current = root;
		string token;
		getline(cin, line);
		istringstream iss(line);
		vector<string> query;
		vector<Tag>::iterator it;

		while (getline(iss, token, '.')) {
			int attr_idx = token.find("~");
			if (attr_idx != -1) {
				string tag = token.substr(0, attr_idx);
				// Look for tag
				current = FindTag(current, tag);

				if (current == NULL) {
					cout << "Not Found!" << endl;
					break;
				}
				string atr = token.substr(attr_idx + 1, token.length() - 1);
				out = findAttr(current, token.substr(attr_idx + 1, token.length() - 1));

				if (out != "") {
					cout << out << endl;
				}
				else cout << "Not Found!" << endl;
			}
			else {
				// Look for tag
				current = FindTag(current, token);

				if (current == NULL) {
					cout << "Not Found!" << endl;
					break;
				}
			}
		}
	}

	getchar();
	return 0;
}