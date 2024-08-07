#pragma once


#include "vulki_pipeline.h"
#include "vulki_device.hpp"
#include "vulki_swap_chain.hpp"
#include "vulki_game_object.hpp"


#include<memory>
#include<vector>

namespace VULKI {

	class SimpleRenderSystem {
	public:


		SimpleRenderSystem(VulkiDevice &device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

		void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<VulkiGameObject> &gameObjects);
	private:

		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);
		


		VulkiDevice &vulkiDevice;

		std::unique_ptr<VulkiPipeline> vulkiPipeline;
		VkPipelineLayout pipelineLayout;

	};
}