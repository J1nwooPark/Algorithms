template <typename K, typename V>
class Entry {
public:
	Entry(const K& k, const V& v) : _key(k), _value(v), left(NULL), right(NULL), par(NULL) {}
	const K& key() const { return _key;  }
	const V& value() const { return _value; }
	Entry* left() const { return _left; }
	Entry* right() const { return _right; }
	Entry* parent() const { return _parent; }
	bool isRoot() const { return par == NULL; }
	bool isExternal() const { return left == NULL && right == NULL; }
	void setKey(const K& k) { _key = k; }
	void setValue(const V& v) { _value = v; }
private:
	K _key;
	V _value;
	Entry* _left;
	Entry* _right;
	Entry* _parent;
};

template <typename E>
class BinarySearchTree {
public:
	typedef typename E::K K;
	typedef typename E::V V;
public:
	class Iterator {
	public: 
		Iterator(const Entry* e) : _e(e) {}
		E& operator*() { return *_e; }
		bool operator==(const Iterator& p) const { return _e == p._e; }
		Iterator& operator++()
		{
			Entry* r = _e->right();
			if (!r->isExternal())
			{
				do {
					_e = r; r = r->left();
				} while(!r.isExternal())
			}
		}
	private:
		Entry* _e;
	};
public:
	BinarySearchTree() : root(NULL), n(0) {};
	int size() const;
	bool empty() const;
	Entry* root() const;
	Entry* finder(const K& k, const Entry* e);
	Entry* inserter(const K& k, const V& v);
	Entry* eraser(Entry* e);
	Entry* restructure(const Entry* e);
	void erase(const K& k);
private:
	Entry* root;
	int n;
};
