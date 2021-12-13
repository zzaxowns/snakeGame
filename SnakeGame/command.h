#pragma once
class command
{
public:
	command();
	virtual ~command();

public:
	virtual void excute() = 0;;
};

