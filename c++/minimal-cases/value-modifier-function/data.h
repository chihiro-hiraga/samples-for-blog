/**
	@file	data.h
	@brief	データオブジェクトクラス宣言
*/
#ifndef MINIMUM_DATA_H
#define MINIMUM_DATA_H

#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <boost/noncopyable.hpp>

namespace minimum {

class Data : private boost::noncopyable {
	struct Impl;
	std::unique_ptr<Impl> impl;

public:
	Data();
	~Data();

	void appendKey(std::string const& key, std::string const& value = std::string{});
	void dropKey(std::string const& key);

	std::string const& operator[](std::string const& key) const;

	struct Detail {
		std::vector<std::string> keys;
		std::vector<std::string> values;
	};

	Data & modify(std::function<void(Detail &)> func);

	struct DetailReference {
		std::vector<std::string> & keys;
		std::vector<std::string> & values;
	};
	typedef void (*UpdateCallBack)(DetailReference const&);

	Data & setUpdateCallBack(UpdateCallBack callback);
};

}	//namespace minimum

#endif	//MINIMUM_DATA_H
