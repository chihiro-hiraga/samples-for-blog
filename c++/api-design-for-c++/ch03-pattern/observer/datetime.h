/**
	@file	datetime.h
	@brief	日時を扱うモデルデータのクラス宣言
*/

#ifndef APIDES_DATETIME_H
#define APIDES_DATETIME_H

#include <memory>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace apides {

namespace p_time = boost::posix_time;

class DateTime : private boost::noncopyable {
	struct Impl;
	std::unique_ptr<Impl> impl;

public:
	explicit DateTime(p_time::ptime const& time = p_time::second_clock::local_time());
	~DateTime();

	std::string toString() const;

	DateTime & updateNow();
};

}	//namespace apides

#endif	//APIDES_DATETIME_H
