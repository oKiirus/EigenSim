#include "stdafx.h"

#include "Particle.h"
#include "ODESolver.h"
#include "SimpleSolver.h"
#include "Camera.h"
#include "Scene.h"

#include "ElectricForce.h"
#include "GravitationalForce.h"
#include "DistanceConstraint.h"


#include "Funcs.h"

#include "Animal.h"




double factorial(int n) {
    return std::tgamma(n + 1);
}



int main()
{

    
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "My window");

    Scene scene(window, new SimpleSolver());
   
    Particle ROOT;
    ROOT.setDerivative(0, Arrow({ 1920/2, 400 }));
    ROOT.setDerivative(1, Arrow({ 0, 0 }));
    ROOT.setDerivative(2, Arrow({ 1, 0 }));
    ROOT.setCompliance(0);
    ROOT.setCharge(10);
    scene.addBody(&ROOT);

    Particle A;
    A.setDerivative(0, Arrow({ 1920/2 + 100, 400 }));
    A.setDerivative(1, Arrow({ 0, 0 }));
    A.setCompliance(1);
    A.setCharge(-10);
    scene.addBody(&A);

    Particle B;
    B.setDerivative(0, Arrow({ 1920 / 2 + 100, 500 }));
    B.setDerivative(1, Arrow({ 0, 0 }));
    B.setCompliance(1);
    B.setCharge(10);
    scene.addBody(&B);

   

    
    GravitationalForce gravity;
    ElectricForce electric(scene.bodies);
    gravity.addToBlacklist(&ROOT);
    electric.addToBlacklist(&ROOT);
    electric.addToBlacklist(&B);
    //scene.addBond(&gravity);
    scene.addBond(&electric);

    //scene.addBond(new ElectricForce(scene.bodies));
    //scene.addConstraint(new DistanceConstraint(&ROOT, &A, 100));
    //scene.addConstraint(new DistanceConstraint(&A, &ROOT, 100));
    //scene.addConstraint(new DistanceConstraint(&A, &B, 100));
    //scene.addConstraint(new DistanceConstraint(&B, &A, 100));


    auto lastTime = std::chrono::high_resolution_clock::now();



    while (window.isOpen())
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = currentTime - lastTime;
        State::frameDeltaTime = elapsed.count() / 10;
        lastTime = currentTime;
        
        while (const std::optional event = window.pollEvent())
        {
        
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        
    
        window.clear(sf::Color::Black);

        scene.render();

        for(int i = 0; i < 10; i++)
            scene.update();
        
        

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        int x = localPosition.x;
        int y = localPosition.y;



        ROOT.setDerivative(1, Arrow({(double)x/100, (double)y/100}));
        


        //std::cout << (PF::ME(&A) + PF::ME(&B)) << "\n";

        window.display();

        render::printHello();
    }

}

