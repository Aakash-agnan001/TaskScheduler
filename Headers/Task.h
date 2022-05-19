#ifndef TASK_H
#define TASK_H

#include "Description.h"
#include "Priority.h"
#include "Classification.h"
#include "UID.h"
#include "Title.h"
#include "Duration.h"
#include "DueDate.h"

Class Task {
	public:
		UID uid;
		Title title;
		DueDate date;
		Description description;
		Classification classification;
		Duration duration;
		Priority priority;
};
