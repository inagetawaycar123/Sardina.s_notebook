from transformers import GPT2Config, GPT2LMHeadModel

mini_config = GPT2Config(
    vocab_size = 1000,
    n_positions = 64,
    n_embd = 64,
    n_layer = 2,
    n_head = 2,
    n_inner = 128,
    activation_function = "gelu",
    resid_pdrop = 0.1,
    embed_pdrop = 0.1,
    attn_pdrop = 0.1,
)

print("模型配置：")
print(mini_config)

model = GPT2LMHeadModel(mini_config)

print("模型结构")
print(model)
print(f"\n总参数量：{sum(p.numel() for p in model.parameters()):,}")

import torch

batch_size = 2
seq_length = 16
input_ids = torch.randint(0, 1000, (batch_size, seq_length))

print(f"\n输入形状：{input_ids.shape}")

with torch.no_grad() :
    outputs = model(input_ids, labels = input_ids)

print(f"输出logits形状：{outputs.logits.shape}")
print(f"损失：{outputs.loss.item():.4f}")