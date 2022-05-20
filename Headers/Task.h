#ifndef TASK_H
#define TASK_H

#include "Description.h"
#include "Priority.h"
#include "Classification.h"
#include "UID.h"
#include "Title.h"
#include "Duration.h"
#include "DueDate.h"

class Task {
	public:
        Task() {
            uid = UID();
            title = Title();
            date = DueDate();
            description = Description();
            classification = Classification();
            duration = Duration();
            priority = Priority();
        };
    public:
		UID uid;
		Title title;
		DueDate date;
		Description description;
		Classification classification;
		Duration duration;
		Priority priority;
};

#endif
