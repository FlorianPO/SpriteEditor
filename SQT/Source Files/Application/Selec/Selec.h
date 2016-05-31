#pragma once

#include "stdafx.h"
#include "Source Files/Retour/Retourable.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/SignalType/SignalController.h"

#define INIT_SELEC CSelec::createInstance();
#define SELEC CSelec::getInstance()

class CSelec : public QObject, private SignalController
{
	Q_OBJECT
// INSTANCE
private:	static CSelec* _t; 
public:		inline static void createInstance() { _t = new CSelec(); }
			inline static CSelec* getInstance() { return _t; }

// CONSTRUCTOR
	CSelec();
	~CSelec() {}

// SIGNALS / SLOTS
	public slots:
		void createSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l);
		void createSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l);
		void deleteSelection();
		void addSelection(sf::IntRect rect,	const std::vector<CTool::line_conf>& conf_l);
		void addSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l);
		void subSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l);
		void subSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l);
		void intersectSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l);
		void intersectSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l);
		void invertSelection();
		void uninvertSelection();
	private slots:
		void createSelection(sf::IntRect rect, const sf::Image* image);
		void sumSelection(sf::IntRect rect, const sf::Image* image, bool add); // add == false -> sub
		void intersectSelection(sf::IntRect rect, const sf::Image* image);
	signals:
		void selectionUpdated(int mode=0); // Always emitted when selection changes : 1 add, 2 sub, 3 intersect
		void selectionCreated();
		void selectionDeleted();
		void selectionInverted();
		void selectionUninverted();
		// CADRE
		void cadreXChanged(int);
		void cadreYChanged(int);
		void cadreWChanged(int);
		void cadreHChanged(int);

// METHODS
public:
	bool isMove();

	void move();
	void afficher_lines();

	void initTest();
	bool onSelec(int x, int y);
	inline bool isSelected() { return conf_lines.size()>0; }
	inline bool isInverted() { return inverted; }
	inline sf::Vector2f getPosition() { return sprite_selec.getPosition(); }
	inline sf::IntRect getCadre() { return cadre; }

	void supr();

protected:
	void initSignals() override;
private:
	void invert();
	void update_cadre();
	void del();
	void reline();
	void setPosLines(sf::Vector2f ex_pos, sf::Vector2f pos);

// MEMBERS
public:
	sf::Color blend_color = sf::Color(255, 255, 255, 0);
	sf::Color ident_color = sf::Color(255, 255, 255, 255);
private:
	bool refresh = true; 
	bool inverted = false;

	sf::IntRect cadre;

	sf::Image image_selec;
	sf::RenderTexture renderTexture_selec;
	sf::Sprite sprite_selec;

	std::vector<CTool::line_conf> conf_lines;

/*
private:
	enum type_retour
	{
		ACT = 0,
		POS,
		INV
	};

	void creer_retour(type_retour t);
	void update(type_retour t);

	int i_retour_type;
	std::vector<type_retour> retour_type;
	int i_retour_inv;
	std::vector<bool> retour_inv;
	int i_retour_pos;
	std::vector<sf::Vector2f> retour_pos;
	int i_retour_image;
	std::vector<sf::Image> retour_image;
	int i_retour_lines;
	std::vector<std::vector<CTool::line_conf>> retour_lines;

public:
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
*/
};

