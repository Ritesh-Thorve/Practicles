#ai: 9 EMPLOYEE PERFORMANCE EVALUATION EXPERT SYSTEM
class ExpertSystem:
    def __init__(self):
        self.facts = {}
        self.rules = []
        self.score = 0
        self.explanations = []

    def add_fact(self, key, value):
        self.facts[key] = value

    def add_rule(self, rule):
        self.rules.append(rule)

    def evaluate(self):
        for rule in self.rules:
            if rule["condition"](self.facts):
                self.score += rule["score"]
                self.explanations.append(rule["message"])
        return self.score, self.explanations


# RULE DEFINITIONS
def create_rules():
    rules = []

    rules.append({
        "condition": lambda f: f["punctuality"] >= 8,
        "score": 10,
        "message": "Excellent punctuality."
    })
    rules.append({
        "condition": lambda f: 5 <= f["punctuality"] < 8,
        "score": 5,
        "message": "Average punctuality."
    })
    rules.append({
        "condition": lambda f: f["punctuality"] < 5,
        "score": -5,
        "message": "Poor punctuality."
    })

    rules.append({
        "condition": lambda f: f["task_completion"] >= 90,
        "score": 15,
        "message": "Consistently completes tasks."
    })
    rules.append({
        "condition": lambda f: 70 <= f["task_completion"] < 90,
        "score": 8,
        "message": "Mostly completes tasks on time."
    })
    rules.append({
        "condition": lambda f: f["task_completion"] < 70,
        "score": -10,
        "message": "Fails to complete tasks sufficiently."
    })

    rules.append({
        "condition": lambda f: f["teamwork"] >= 8,
        "score": 10,
        "message": "Strong teamwork skills."
    })
    rules.append({
        "condition": lambda f: f["teamwork"] < 5,
        "score": -5,
        "message": "Weak teamwork skills."
    })

    rules.append({
        "condition": lambda f: f["innovation"] >= 7,
        "score": 8,
        "message": "Shows innovation at work."
    })

    rules.append({
        "condition": lambda f: f["leadership"] >= 8,
        "score": 10,
        "message": "Demonstrates strong leadership qualities."
    })

    return rules


# FINAL DECISION LOGIC
def final_grade(score):
    if score >= 40:
        return "Outstanding"
    elif 30 <= score < 40:
        return "Very Good"
    elif 20 <= score < 30:
        return "Good"
    elif 10 <= score < 20:
        return "Satisfactory"
    else:
        return "Needs Improvement"


# MAIN PROGRAM
def main():
    print("\n=== Employee Performance Evaluation Expert System ===")

    punctuality = int(input("Rate Punctuality (0-10): "))
    task_completion = int(input("Task Completion Rate (0-100): "))
    teamwork = int(input("Rate Teamwork (0-10): "))
    innovation = int(input("Rate Innovation (0-10): "))
    leadership = int(input("Rate Leadership (0-10): "))

    system = ExpertSystem()

    # Add facts
    system.add_fact("punctuality", punctuality)
    system.add_fact("task_completion", task_completion)
    system.add_fact("teamwork", teamwork)
    system.add_fact("innovation", innovation)
    system.add_fact("leadership", leadership)

    # Add rules
    for rule in create_rules():
        system.add_rule(rule)

    score, explanations = system.evaluate()

    print("\n=== Evaluation Result ===")
    print(f"Total Score: {score}")
    print("Performance Level:", final_grade(score))

    print("\nReasoning:")
    for explanation in explanations:
        print(" -", explanation)

    print("\nThank you for using the expert system!")


if __name__ == "__main__":
    main()
