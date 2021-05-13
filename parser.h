#ifndef PARSER_H__
#define PARSER_H__



class Parser {
public:
	Parser();
	std::vector<std::vector<int> > load_matrix(const char *filename);
};

#endif
