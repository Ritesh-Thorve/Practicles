#ai: 10 Expert System: Information Management System (IMS)

class KnowledgeBase:
    def __init__(self):
        self.rules = []
        self.facts = {}
    def add_rule(self, rule):
        self.rules.append(rule)
    def add_fact(self, key, value):
        self.facts[key] = value

class Rule:
    def __init__(self, conditions, action):
        self.conditions = conditions  # dict
        self.action = action          # function
    def matches(self, facts):
        for key, expected_value in self.conditions.items():
            if key not in facts or facts[key] != expected_value:
                return False
        return True

class InferenceEngine:
    def __init__(self, kb: KnowledgeBase):
        self.kb = kb
    def run(self):
        actions_taken = []
        for rule in self.kb.rules:
            if rule.matches(self.kb.facts):
                result = rule.action()
                actions_taken.append(result)
        return actions_taken

# Expert System Behavior — Rules
def create_ims_expert_system():
    kb = KnowledgeBase()
    # ---- Rules ----
    kb.add_rule(Rule(
        conditions={"type": "financial", "sensitivity": "high"},
        action=lambda: "Store in ENCRYPTED database with restricted access."
    ))
    kb.add_rule(Rule(
        conditions={"type": "hr", "sensitivity": "medium"},
        action=lambda: "Store in secure internal storage with role-based access."
    ))
    kb.add_rule(Rule(
        conditions={"type": "technical", "sensitivity": "low"},
        action=lambda: "Store in general knowledge repository."
    ))
    kb.add_rule(Rule(
        conditions={"retention": "long"},
        action=lambda: "Apply archival policy: retain for 7+ years."
    ))
    kb.add_rule(Rule(
        conditions={"retention": "short"},
        action=lambda: "Retain only for 1 year; auto-delete afterward."
    ))
    return kb

# Run Expert System
def run_ims_expert_system():
    kb = create_ims_expert_system()
    # --- User Input ---
    print("=== Information Management Expert System ===")
    doc_type = input("Enter document type (financial, hr, technical): ").lower()
    sensitivity = input("Enter sensitivity (high, medium, low): ").lower()
    retention = input("Enter retention period (long, short): ").lower()
    kb.add_fact("type", doc_type)
    kb.add_fact("sensitivity", sensitivity)
    kb.add_fact("retention", retention)
    engine = InferenceEngine(kb)
    results = engine.run()
    print("\n--- System Recommendations ---")
    for r in results:
        print("• " + r)
if __name__ == "__main__":
    run_ims_expert_system()
