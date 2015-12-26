#include "Calque.h"
#include "BoutonView.h"
#include "BoutonSwitch.h"
#include "Gui.h"

void CCalque::GuiConstructor()
{
	panneau = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 401, 129, hauteur_c), NULL, sf::IntRect(131, 401, 129, hauteur_c));
	b_vignette = new CBoutonView(sprite.getTexture(), sf::IntRect(50, 4, 43, 26));
	
	b_oeil = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 401, 31, 31), sf::Vector2f(3, 0));
	auto fonction = new std::function<void(fonction_type)>([](fonction_type l) {static_cast<CCalque*>(l[0])->setVisible(!static_cast<CCalque*>(l[0])->isVisible()); });
	auto arguments = new fonction_type{ this };
	auto predicat = new std::function<int(fonction_type)>([](fonction_type l) {return static_cast<CCalque*>(l[0])->isVisible(); });
	b_oeil->setFonction(fonction);
	b_oeil->setPredicat(predicat);
	b_oeil->setArguments(arguments);

	panneau->addBouton(b_vignette);
	panneau->addBouton(b_oeil);

	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return _t == l[0]; }); panneau->setPredicatSwap(predicat);
	arguments = new fonction_type{ this }; panneau->setArguments(arguments);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {_t = static_cast<CCalque*>(l[0]); });
	panneau->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return !static_cast<CCalque*>(l[0])->isDead();});
	panneau->setPredicatScroll(predicat);

	panneau->group(GUI->getPanneauAboveCalque());
	if (nbrCalque() == 0)
	{
		GUI->getPanneauBelowCalque()->group(panneau);
		panneau->affectMoveGroup(new std::function<void(int, int)>([](int i_src, int i_dst)
		{
			i_src = CALQUE_LIST.size() - (i_src - CPanneau::whichPosition(GUI->getPanneauAboveCalque()));
			i_dst = CALQUE_LIST.size() - (i_dst - CPanneau::whichPosition(GUI->getPanneauAboveCalque()));
			CCalque* tmp = CALQUE_LIST[i_src];
			CALQUE_LIST.erase(CALQUE_LIST.begin() + i_src);
			CALQUE_LIST.insert(CALQUE_LIST.begin() + i_dst, tmp);
		}));
	}
	else
		panneau->setMoveGroup(calque_list[0]->panneau);
}