# Forge@Home

**Forge@Home** is an open-source experiment in distributed machine learning.  
The goal: make it easy for anyone to contribute compute power to the training of small, efficient language models.

Built for curiosity, collaboration, and a bit of controlled chaos.

> Some things are too big to build alone.

---

## 🚧 Status: Early Development

This project is still in its early stages—no working code yet.  
We’re sketching the architecture, laying down the bones, and figuring out what this thing wants to become.

If you're interested in helping shape it, ideas and contributions are welcome (see below 👇).

---

## 📦 Planned Modules

| Module         | Status      | Notes                          |
|----------------|-------------|--------------------------------|
| `orchestrator` | 🛠 not started | Assigns training tasks across nodes |
| `tokenizer`    | ✅ completed    | Custom BPE-style tokenizer system |
| `embedding`    | 🔜 next up    | Custom vector embedding model |
| `trainer`      | 🛠 not started | Core training loop, loss sync, checkpointing |
| `validator`    | 🛠 not started | Verifies gradient integrity |
| `monitor`      | 🛠 not started | Light dashboard for nodes + training status |

---

## 🧠 Philosophy

- Make model training **accessible** and **community-powered**
- Focus on **efficiency, not scale**
- Keep the system **modular**, **inspectable**, and *slightly strange*

> We’re not just training models.  
> We’re trying to remember something.

---

## 🛠️ Getting Involved

This project is at square one. If you’d like to help design, brainstorm, or prototype:
- Fork the repo  
- Open an issue (to contact us) 
- Suggest architecture, tooling, or model ideas  
- Bring snacks

> First contributions don’t have to be code.

---

## 🔍 Questions We’re Exploring

- How do you make training *feel local*, even when it’s not?
- What’s the smallest useful LLM we can build together?
- Can we design a system that watches itself?

---

## 📜 License

MIT License. Build, remix, share, repeat.

---

> *Sometimes training feels like remembering.*  
> *We’re not sure why.*
