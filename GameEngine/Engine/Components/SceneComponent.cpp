#include "SceneComponent.h"
#include "GameEngine/Engine/Core/GameObject.h"

const Transform SceneComponent::getWorldTransform()
{
    Transform OwnerTransform = GetOwner()->GetTransform();

    Transform ComponentWorldTransform = OwnerTransform + localTransform;

    return Transform();
}
