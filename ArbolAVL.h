#pragma once

template <class T>
struct Node {
public:
	T key;
	//int key;
	struct Node *left;
	struct Node *right;
	int height;
	char* Apellido, Nombre;
	int Edad, DNI, Codigo;
	//------
	Node() {
		left = right = nullptr;
		height = 0;
		key = 0;
	}
	//------
	~Node() {
		left = right = nullptr;
		height = 0;
		key = 0; //nullptr
	}
};



template <class T>
class ArbolAVL {
private:
	Node<T>* raiz;
	void(*procesar)(T); //function pointer

	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	//-----------------------------------
	void _insertar(Node<T>*& nodo, T e, T _apellido, T _nombre, T _edad, T _dni, T _codigo)
	{
		if (nodo == nullptr) {
			nodo = new Node<T>();
			nodo->key = e;
			nodo->Apellido = _apellido;
			nodo->Nombre = _nombre;
			nodo->Edad = _edad;
			nodo->DNI = _dni;
			nodo->Codigo = _codigo;
		}
		else if (e < nodo->key) {
			_insertar(nodo->left, e, _apellido, _nombre, _edad, _dni, _codigo);
		}
		else if (e >= nodo->key) {
			_insertar(nodo->right, e, _apellido, _nombre, _edad, _dni, _codigo);
		}
	}
	//-----------------------------------
	void _inOrder(Node<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrder(nodo->left);
		procesar(nodo->key);
		_inOrder(nodo->right);
	}
	//-----------------------------------
	void _preOrder(Node<T>* nodo) {
		if (nodo == nullptr) return;
		procesar(nodo->key);
		_inOrder(nodo->left);
		_inOrder(nodo->right);
	}
	//===================================================================
	Node<T>* _quitarMenor(Node<T>*parent, Node<T>*& _parent) {
		if (parent == nullptr) return nullptr; // ERROR!!
		if (parent->left == nullptr) { // encontramos el menor!!
			_parent = parent->right;
			parent->right = nullptr;
			return parent;
		}
		else {
			return _quitarMenor(parent->left, parent->left);
		}
	}

	Node<T>* _quitarMayor(Node<T>*parent, Node<T>*& _parent) {
		if (parent == nullptr) return nullptr; // ERROR!!
		if (parent->right == nullptr) { // encontramos el menor!!
			_parent = parent->left;
			parent->left = nullptr;
			return parent;
		}
		else {
			return _quitarMayor(parent->right, parent->right);
		}
	}
	//===================================================================    

	//Funciones a implementar
	void _OrdenarPorEdad() {}
	void _OrdenarPorCodigo() {}
	void _OrdenarPorNombre() {}
	void _OrdenarPorApellido() {}
	void _OrdenarPorDNI() {}

public:
	/*ArbolAVL(void(*pf)(T)) {
		this->procesar = pf;
		raiz = nullptr;
	}*/
	ArbolAVL() {}

	//-----------------------------------
	void insertar(T e,T apellido,T nombre,T edad ,T dni,T codigo) {
		_insertar(raiz, e, apellido, nombre, edad, dni, codigo);
	}
	//-----------------------------------
	void inOrder() { _inOrder(raiz); }
	void preOrder() { _preOrder(raiz); }
	T quitarMenor() {
		Node<T>* deleted = _quitarMenor(raiz, raiz);
		return deleted->key;

	}

	T quitarMayor() {
		Node<T>* deleted = _quitarMayor(raiz, raiz);
		return deleted->key;
	}
	//-----------------------------------

};