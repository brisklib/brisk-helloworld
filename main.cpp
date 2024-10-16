#include <brisk/gui/Component.hpp>
#include <brisk/gui/Graphene.hpp>
#include <brisk/widgets/Button.hpp>
#include <brisk/widgets/Layouts.hpp>
#include <brisk/widgets/Text.hpp>
#include <brisk/gui/GUIApplication.hpp>

using namespace Brisk;

class RootComponent : public Component {
public:
  RC<Widget> build() final {
    return rcnew VLayout{
        stylesheet = Graphene::stylesheet(),
        Graphene::darkColors(),
        gapRow = 8_px,
        alignItems = AlignItems::Center,
        justifyContent = Justify::Center,
        new Text{"Hello, world"},
        new Button{
            new Text{"Quit"},
            onClick = m_lifetime | []() { windowApplication->quit(); },
        },
    };
  }
};

int briskMain() {
  GUIApplication application;

  return application.run(createComponent<RootComponent>());
}