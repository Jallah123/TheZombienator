#include "AbstractScreen.h"
#include "TextureFactory.h"

AbstractScreen::AbstractScreen()
{
}

AbstractScreen::AbstractScreen(SDL_Renderer * ren) : renderer(ren)
{
}


AbstractScreen::~AbstractScreen()
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = NULL;
	for each (auto component in UIComponents)
	{
		delete component;
	}
	UIComponents.clear();
}

void AbstractScreen::AddUIComponent(AbstractUIComponent* UIComponent)
{
	UIComponents.push_back(UIComponent);
}

void AbstractScreen::ClickComponents(SDL_Point MousePosition)
{
	std::vector<AbstractUIComponent*>::iterator i = UIComponents.begin();
	while (i != UIComponents.end())
	{
		(*i)->OnClick(MousePosition);

		if (UIComponents.size() <= 0) {
			break;
		}

		i++;
	}
}

void AbstractScreen::ChangeBackground(SDL_Renderer * ren, char * img_url)
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = TextureFactory::GenerateTextureFromImgUrl(img_url);
}
