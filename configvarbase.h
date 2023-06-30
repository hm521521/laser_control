#ifndef CONFIGVARBASE_H
#define CONFIGVARBASE_H
class ConfigVarBase{
public:
    typedef std::shared_ptr<ConfigVarBase> ptr;
    ConfigVarBase(const std::string& name,const std::string& description="")
        :m_name(name)
        ,m_description(description){
        std::transform(m_name.begin(),m_name.end(),m_name.begin(),::tolower);
    }
    virtual ~ConfigVarBase(){}
    const std::string& getName() const{return m_name;}
    const std::string& getDescription() const{return m_description;}
    virtual bool fromString(const std::string& val)=0;
    virtual std::string getTypeName() const=0;
protected:
    std::string m_name;
    std::string m_description;
};

template<class F, class T>
class LexicalCast //类型转换模板类(F源类型，T 目标类型)
{
public:
    T operator()(const F& v) {
        return boost::lexical_cast<T>(v);
    }
};

template<class T>
class LexicalCast<std::string, std::vector<T> >//类型转换模板类片特化(YAML String 转换成 std::vector<T>)
{
public:
    std::vector<T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::vector<T> vec;
        std::stringstream ss;
        for(size_t i = 0; i < node.size(); ++i) {
            ss.str("");
            ss << node[i];
            vec.push_back(LexicalCast<std::string, T>()(ss.str()));
        }
        return vec;
    }
};


template<class T>
class LexicalCast<std::vector<T>, std::string> //类型转换模板类片特化(std::vector<T> 转换成 YAML String)
{
public:
std::string operator()(const std::vector<T>& v) {
    YAML::Node node(YAML::NodeType::Sequence);
    for(auto& i : v) {
        node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
    }
    std::stringstream ss;
    ss << node;
    return ss.str();
}
};

#endif // CONFIGVARBASE_H
