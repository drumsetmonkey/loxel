#include <game_class.hpp>
#include <script/script.hpp>
#include <script/script_exception.hpp>

namespace GameState
{
    Configuration clientConfig;
    bool running = true;
    Game* gameObj;

    void createConfig()
    {
        const std::string configFile = "config/loxel.conf";

        try {
            clientConfig.loadfile(configFile);
        } catch (ScriptException::FileNotFound &fnf) {
            clientConfig.createfile(configFile);
            clientConfig.loadfile(configFile);
        }
    }

    void readConfig()
    {

        clientConfig.readConfig();
    }

    void stopGame()
    {
        running = false;
    }

    bool isRunning()
    {
        return running;
    }

    void setGameObject(Game* obj)
    {
        gameObj = obj;
    }

    Game* gameObject()
    {
        return gameObj;
    }

    void cleanup()
    {
        gameObj = NULL;
    }
}
