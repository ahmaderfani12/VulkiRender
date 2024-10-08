#pragma once


#include "vulki_pipeline.h"
#include "vulki_device.hpp"
#include "vulki_swap_chain.hpp"
#include "vulki_game_object.hpp"
#include "vulki_camera.hpp"
#include "vulki_frame_info.hpp"

#include<memory>
#include<vector>

namespace VULKI {

	class SimpleRenderSystem {
	public:


		SimpleRenderSystem(VulkiDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

		void renderGameObjects(FrameInfo &frameInfo);
	private:

		void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
		void createPipeline(VkRenderPass renderPass);
		


		VulkiDevice &vulkiDevice;

		std::unique_ptr<VulkiPipeline> vulkiPipeline;
		VkPipelineLayout pipelineLayout;

	};
}