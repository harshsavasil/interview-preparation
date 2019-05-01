import enum
import itertools
import random
import sys


class DifficultyLevel(enum.Enum):
    easy = 1
    medium = 2    
    hard = 3

class Question(object):
    """
    A class describing a 'Question'. A question has following attributes: 
    
    :param id: An uniue auto-increment id for every question.
    :param question: A string representing the question's text.
    :param difficulty: An int defining the difficulty of the question.
    :param marks: An int representing the marks of question.
    """
    allowedDifficulty = [difficulty for difficulty in DifficultyLevel]
    newid = itertools.count().next

    def __init__(self, question_text, difficulty, marks):
        """
        """
        if difficulty not in self.allowedDifficulty:
            msg = "%s is not a valid difficulty level.\n" % difficulty
            msg += "There are only three types of difficulty level.\n"
            for difficulty in self.allowedDifficulty:
                msg += "{0} - {1}\n".format(difficulty.value, DifficultyLevel(difficulty))
            raise ValueError(msg)
        self.id = self.newid()
        self.question_text = question_text
        self.marks = int(marks)
        self.difficulty = difficulty

class QuestionBank(object):
    """
    A pool of questions.
    """

    def __init__(self):
        self.easy_questions = []
        self.medium_questions = []
        self.hard_questions = []

    def add_easy_question(self, question, marks):
        new_question = Question(question, DifficultyLevel.easy, marks)
        self.easy_questions.append(new_question)

    def add_medium_question(self, question, marks):
        new_question = Question(question, DifficultyLevel.medium, marks)
        self.medium_questions.append(new_question)

    def add_hard_question(self, question, marks):
        new_question = Question(question, DifficultyLevel.hard, marks)
        self.hard_questions.append(new_question)

class QuestionPaperGenerator(object):
    """
    A Class that generates question paper by randomly picking questions from
    different pools of questions based on the difficulty and marks.
    Currently, it uses recursive subset sum algorithm 
    to find out the question set for a fixed total marks.
    """
    total_marks = 100
    _possible_easy_question_sets = []
    _possible_medium_question_sets = []
    _possible_hard_question_sets = []
    subset_sum_table = []
    question_bank = None
    easy_questions_pecentage = None
    medium_questions_pecentage = None
    hard_questions_pecentage = None
    question_paper = None

    def setup_easy_questions(self):
        easy_question_file = 'easy_questions.txt'
        easy_questions = [line.rstrip('\n') for line in open(easy_question_file)]
        for easy_question in easy_questions:
            question = easy_question.split("|")[0].strip()
            marks = easy_question.split("|")[1].strip()
            self.question_bank.add_easy_question(question, marks)

    def setup_medium_questions(self):
        medium_question_file = 'medium_questions.txt'
        medium_questions = [line.rstrip('\n') for line in open(medium_question_file)]
        for medium_question in medium_questions:
            question = medium_question.split("|")[0].strip()
            marks = medium_question.split("|")[1].strip()
            self.question_bank.add_medium_question(question, marks)

    def setup_hard_questions(self):
        hard_question_file = 'hard_questions.txt'
        hard_questions = [line.rstrip('\n') for line in open(hard_question_file)]
        for hard_question in hard_questions:
            question = hard_question.split("|")[0].strip()
            marks = hard_question.split("|")[1].strip()
            self.question_bank.add_hard_question(question, marks)

    def create_question_bank(self):
        self.setup_easy_questions()
        self.setup_medium_questions()
        self.setup_hard_questions()

    def __init__(self):
        # create Question bank
        self.question_bank = QuestionBank()
        self.create_question_bank()
        self.easy_questions_pecentage = 20
        self.medium_questions_pecentage = 50
        self.hard_questions_pecentage = 30
        self.question_paper = []

    def mask(self, questions, bitmask):
        """
        This method uses bitmasking to create new subsets.
        :param bitmask, a string representing a bitmask of number between 0 and 2^no_of_elements
        :param questions, a list of questions
        """
        bitmask = bitmask.zfill(len(questions))
        return map(lambda x: x[0], filter(lambda x: x[1] != '0', zip(
            questions, bitmask)))

    def get_question_sets(self, questions, marks):
        """ 
        This method takes question set and marks as input and creates
        a question set containing the questions whose sum is equal to
        the marks. 
        :param questions, a list of questions
        :param marks, a int reprsenting the marks of the question set.
        """
        no_of_questions = len(questions)
        for i in range(2**no_of_questions):
            # Check the total marks of current subset.
            question_set = self.mask(questions, bin(i)[2:])
            if sum(question.marks for question in question_set) == marks:
                yield question_set

    def create_paper(self):
        """
        We can parameterise the ratio of different type of questions.
        For simplicity, I have assumed the following ratio - 
            20 marks for easy questions
            50 marks for medium questions
            30 marks for hard questions
        """
        self._possible_easy_question_sets = list(self.get_question_sets(
            self.question_bank.easy_questions, self.easy_questions_pecentage))
        self._possible_medium_question_sets = list(self.get_question_sets(
            self.question_bank.medium_questions, self.medium_questions_pecentage))
        self._possible_hard_question_sets = list(self.get_question_sets(
            self.question_bank.hard_questions, self.hard_questions_pecentage))

        self.question_paper.extend(random.choice(self._possible_easy_question_sets))
        self.question_paper.extend(random.choice(self._possible_medium_question_sets))
        self.question_paper.extend(random.choice(self._possible_hard_question_sets))

    def display_question_paper(self):
        total_marks = 0
        for index, question in enumerate(self.question_paper):
            total_marks += question.marks
            print "{0}. {1} {2} marks \n".format(
                index + 1, question.question_text, question.marks)
        print "Total Marks : {0}".format(total_marks)


if __name__ == "__main__":
    question_paper_generator = QuestionPaperGenerator()
    question_paper_generator.create_paper()
    question_paper_generator.display_question_paper()
