#include <ansi.h>
int update_player(object me);


int main(object me, string arg)
{
        object ob;
        string party,obj;
	mapping skill;
	string *skl;
        int i;
        int level=465;
        if( !arg )      return notify_fail("setparty <obj> <party>\n");
        if( !arg || sscanf(arg, "%s %s", obj, party)!=2 )
                return notify_fail("setskill <obj> <party>\n");
        ob = find_player(obj);
        if( !ob )       ob = find_living(obj);
        if( !ob )       ob = present(obj, environment(me));
        if( !ob ) return notify_fail("�Ҳ����������.\n");
        if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
                return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
        if( userp(ob) && ob->query("no_call") )
                return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
        if( (wiz_level(me) < wiz_level("(arch)")) && me!=ob )
                return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
	if (party!="mj" && party!="gb" && party!="wd" && party!="tz" && party!="thd" && party!="hs" &&
	    party!="ss" && party!="sl" && party!="dls" && party!="gm" && party!="tls" && party!="sld" &&
	    party!="em" && party!="xx" && party!="mr") return notify_fail("no this party.\n");
        write(WHT"begin setting party for "NOR + ob->short(1) + WHT"��\n"NOR);
        
          ob->set("neili",2000);
          ob->set("max_neili",2000);
          ob->set("eff_neili",2000);
          ob->set("jingli",2000);
          ob->set("max_jingli",2000);
          ob->set("eff_jingli",2000);
          ob->set("qi",12000);
          ob->set("max_qi",1500);
          ob->set("eff_qi",1500);
          ob->set("jing",2000);
          ob->set("max_jing",2000);
          ob->set("eff_jing",2000);
          ob->set("mud_age",1028939);
          ob->set("combat_exp",100000);
          ob->delete("enter_wuguan");
        
        
        
	  ob->set_skill("lingbo-weibu",9000);
	  skill = ob->query_skills();
	  skl = keys(skill);
	  i = sizeof(skl);
	  while (i--) {
	  	ob->delete_skill(skl[i]);
	  	}

	  ob->set_skill("dodge",level);
	  ob->set_skill("force",level);
	  ob->set_skill("parry",level);
	  ob->set_skill("literate",me->query("int")*10);
	  ob->set_skill("wuxing-zhen",200);
	  ob->set_skill("sword",level);
	  ob->set_skill("cuff",level);
	  ob->set_skill("medicine",200);



if(party=="gb")
{
        ob->set("gb_job",1000);
        ob->set("gb_job2",1000);
        ob->set("snake_job",2000);
        ob->set_skill("huntian-qigong", level);
        ob->set_skill("xiaoyaoyou", level);
        ob->set_skill("begging",200);
        ob->set_skill("stealing",200);
        ob->set_skill("bangjue",200);
        ob->set_skill("checking",200);
        ob->set_skill("strike",level);
        ob->set_skill("xianglong-zhang",level);
        ob->set_skill("stick",level);
        ob->set_skill("dagou-bang",level);

}
if (party=="mj")
{
        ob->set("mingjiao_job",200);
        ob->set_skill("shenghuo-shengong", level);
              ob->set_skill("jiuyang-shengong", level);
              ob->set_skill("tiyunzong", level);
        ob->set_skill("piaoyi-shenfa", level);
        ob->set_skill("qiankun-danuoyi",level);
        ob->set_skill("hand",level);
        ob->set_skill("yingzhua-shou",level);
        ob->set_skill("strike",level);
        ob->set_skill("hanbing-mianzhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("qishang-quan",level);
        ob->set_skill("shenghuo-lingfa",level);
        ob->set_skill("dagger",level);
}
if(party=="wd")
{
	ob->set("wd_job",200);
        ob->set_skill("yinyun-ziqi", level);
        ob->set_skill("tiyunzong", level);
        ob->set_skill("taoism",200);
        ob->set_skill("cuff",level);
        ob->set_skill("taiji-quan",level);
        ob->set_skill("sword",level);
        ob->set_skill("taiji-jian",level);
        ob->set_skill("zhenshan-mianzhang",level);
        ob->set_skill("strike", level);
}

if (party=="tz")
{ 
	ob->set_skill("guiyuan-tunafa", level);
	ob->set_skill("shuishangpiao", level);
	ob->set_skill("strike", level);
	ob->set_skill("axe", level);
	ob->set_skill("brush", level);
	ob->set_skill("lietian-fu", level);
	ob->set_skill("yingou-bifa", level);
	ob->set_skill("tiezhang-zhangfa", level);
	ob->set_skill("tiezhang-xinfa",200);

}
if (party=="sld")
{ 
	ob->set("family/master_id","hong antong");
	ob->set_skill("huagu-mianzhang", level);
	ob->set_skill("dulong-dafa", level);
	ob->set_skill("hansha-sheying", level);
	ob->set_skill("throwing", level);
	ob->set_skill("youlong-shenfa", level);
	ob->set_skill("lingshe-bianfa", level);
	ob->set_skill("whip", level);
	ob->set_skill("shenlong-yaoli", 200);
	ob->set_skill("canglang-goufa", level);
	ob->set_skill("hook", level);
	ob->set_skill("leg", level);
        ob->set_skill("poison", 200);
        ob->set_skill("dagger", level);
        ob->set_skill("tenglong-bifa", level);
	ob->set_skill("shenlong-tuifa", level);
	ob->set_skill("strike", level);

}
if(party=="thd")
{
	ob->set("thd/perform",31);

	ob->set("thd_job",200);
        ob->set_skill("bihai-chaosheng", level);
        ob->set_skill("suibo-zhuliu", level);
        ob->set_skill("qimen-bagua",200);
        ob->set_skill("leg",level);
        ob->set_skill("xuanfeng-tui",level);
        ob->set_skill("taoism",200);
        ob->set_skill("hand",level);
        ob->set_skill("lanhua-shou",level);
        ob->set_skill("finger",level);
        ob->set_skill("tanzhi-shentong",level);
        ob->set_skill("strike",level);
        ob->set_skill("luoying-zhang",level);
        ob->set_skill("sword",level);
        ob->set_skill("yuxiao-jian",level);
        ob->set_skill("throwing",level);
}
if(party=="hs")
{
	ob->set("hs_job",200);
	ob->set_skill("blade", level);
	ob->set_skill("sword", level);
	ob->set_skill("cuff", level);
	ob->set_skill("strike", level);
	ob->set_skill("zixia-gong", level);
	ob->set_skill("ziyin-yin", level);
	ob->set_skill("zhengqi-jue", 200);
	ob->set_skill("poyu-quan", level);
	ob->set_skill("fanliangyi-dao", level);
 	ob->set_skill("huashan-jianfa", level);
	ob->set_skill("hunyuan-zhang", level);
	ob->set_skill("huashan-shenfa",level);
}
if(party=="ss")
{
        ob->set("songshan_points",310);
        ob->set_skill("hanbing-zhenqi", level);
        ob->set_skill("zhongyuefeng", level);
        ob->set_skill("strike",level);
        ob->set_skill("hand",level);
        ob->set_skill("songyang-shou",level);
        ob->set_skill("sword",level);
        ob->set_skill("songshan-jian",level);

}
if(party=="sl")
{
	ob->set("sl_job",200);
        ob->set_skill("yijin-jing", level);
        ob->set_skill("shaolin-shenfa", level);
        ob->set_skill("ruying-suixingtui", level);
        ob->set_skill("buddhism",200);
        ob->set_skill("leg",level);
        ob->set_skill("hand",level);
        ob->set_skill("qianye-shou",level);
        ob->set_skill("finger",level);
        ob->set_skill("yizhi-chan",level);
        ob->set_skill("strike",level);
        ob->set_skill("banruo-zhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("jingang-quan",level);
        ob->set_skill("claw",level);
        ob->set_skill("longzhua-gong",level);
        ob->set_skill("club",level);
        ob->set_skill("weituo-chu",level);
        ob->set_skill("blade",level);
        ob->set_skill("ranmu-daofa",level);
        ob->set_skill("whip",level);
        ob->set_skill("riyue-bian",level);
        ob->set_skill("luohan-quan",level);
        ob->set("fenwo",level);
 }
if(party=="dls")
{
     	ob->set("xs_job",200);
     	ob->set_skill("longxiang-boruo", level);
        ob->set_skill("yuxue-dunxing", level);
        ob->set_skill("huanxi-chan",200);
        ob->set_skill("hand",level);
        ob->set_skill("dashou-yin",level);
        ob->set_skill("hammer",level);
        ob->set_skill("xiangfu-lun",level);
        ob->set_skill("claw",level);
        ob->set_skill("jiuyin-baiguzhua",level);
        ob->set_skill("blade",level);
        ob->set_skill("xuedao-jing",level);
}
if(party=="gm")
{
        ob->set_skill("yunu-xinjing", level);
        ob->set_skill("yunu-shenfa", level);
        ob->set_skill("strike",level);
        ob->set_skill("jiuyin-zhengong", 200);
        ob->set_skill("jiuyin-shenfa", 200);
        ob->set_skill("daode-jing", 300);
        ob->set_skill("claw", 200);
        ob->set_skill("jiuyin-baiguzhua", 200);
        ob->set_skill("sword",level);
        ob->set_skill("tianluo-diwang",level);
        ob->set_skill("quanzhen-jianfa",level);
        ob->set_skill("xuantie-jianfa",level);
        ob->set_skill("anran-zhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("meinu-quanfa",level);
        ob->set_skill("yunu-jianfa",level);
        ob->set_skill("whip",level);
        ob->set_skill("yinsuo-jinling",level);
        ob->set_skill("quanzhen-jianfa",level);
 }
if(party=="tls")
{
	  ob->set("dali_job",1500);
 	  ob->set_skill("qiantian-yiyang",level);
        ob->set_skill("kurong-changong", level);
        ob->set_skill("tianlong-xiang", level);
        ob->set_skill("strike",level);
        ob->set_skill("qingyan-zhang",level);
        ob->set_skill("liumai-jianzhen", 200);
        ob->set_skill("finger",level);
        ob->set_skill("yiyang-zhi",level);
        ob->set_skill("sword",level);
        ob->set_skill("duanjia-jianfa",level); 
        ob->set_skill("cihang-bian",level);
        ob->set_skill("whip",level);
        ob->set_skill("buddhism",200);
}
if(party=="em")
{       
        ob->set_skill("linji-zhuang", level);
        ob->set_skill("anying-fuxiang", level);
        ob->set_skill("dacheng-fofa",200);
        ob->set_skill("daode-jing", 300);
//        ob->set_skill("jiuyin--zhengong", 200);
//        ob->set_skill("jiuyin-shenfa", 200);
        ob->set_skill("claw", 300);
//        ob->set_skill("jiuyin-baiguzhua", 300);
        ob->set_skill("sixiang-zhang",level);
        ob->set_skill("hand",level);
        ob->set_skill("jieshou-jiushi",level);
        ob->set_skill("sword",level);
        ob->set_skill("huifeng-jian",level);
        ob->set_skill("strike",level);
        ob->set_skill("blade",level);
        ob->set_skill("yanxing-daofa",level);
}
if(party=="xx")
{       
        ob->set("xx_points",510);
        ob->set("xx_job5",510);
        ob->set("xx_job4",510);
        ob->set_skill("huagong-dafa", level);
        ob->set_skill("zhaixingshu", level);
        ob->set_skill("poison",300);
        ob->set_skill("strike",level);
        ob->set_skill("chousui-zhang",level);
        ob->set_skill("claw",level);
        ob->set_skill("sanyin-zhua",level);
        ob->set_skill("staff",level);
        ob->set_skill("tianshan-zhang",level);
 }
if(party=="mr")
{       
        ob->set_skill("murong-jianfa", level);
        ob->set_skill("canhe-zhi", level);
        ob->set_skill("strike",level);
        ob->set_skill("sword",level);
        ob->set_skill("xingyi-zhang",level);
        ob->set_skill("xingyi-jianzhen",level);
        ob->set_skill("finger",level);
        ob->set_skill("shenyuan-gong",level);
        ob->set_skill("douzhuan-xingyi",level);
        ob->set_skill("yanling-shenfa",level);
 }
if(party=="wudu")
{       
        ob->set_skill("sword",level);
        ob->set_skill("jinshe-jianfa",level);
        ob->set_skill("strike",level);
        ob->set_skill("jinshe-zhangfa",level);        
        ob->set_skill("yinyun-ziqi", level);
        ob->set_skill("finger",level);
              ob->set_skill("poison",300);
        ob->set_skill("qianzhu-wandushou",level);
        ob->set_skill("xiaoyaoyou",level);

 }
if(party=="tiandi")
{       
        ob->set_skill("blade", level);
        ob->set_skill("cuff",level);
        ob->set_skill("taizu-quan",level);
        ob->set_skill("blade",level);
        ob->set_skill("wuhu-duanobndao", level);
        ob->set_skill("huntian-qigong",level);
        ob->set_skill("xiaoyaoyou",level);
 }
if(party=="kunlun")
{       
        ob->set_skill("sword", level);
        ob->set_skill("cuff",level);
        ob->set_skill("blade",level);
              ob->set_skill("sword",level);
              ob->set_skill("kuang-jian",level);
        ob->set_skill("wind-blade",level);
        ob->set_skill("xuantian-wuji",level);
        ob->set_skill("xunlei-jian",level);
        ob->set_skill("xuangong-quan", level);
        ob->set_skill("yinyun-ziqi",level);
        ob->set_skill("xixin-dafa",level);
        ob->set_skill("tiyunzong",level);
 }
if(party=="xiaoyao")
{       
        ob->set_skill("finger", level);
        ob->set_skill("blade",level);
        ob->set_skill("finger",level);
           ob->set_skill("sword",level);
              ob->set_skill("kuang-jian",level);
            ob->set_skill("yiyang-zhi",level);
        ob->set_skill("beiming-shengong",level);
        ob->set_skill("liumai-shenjian",300);
        ob->set_skill("kurong-changong", level);
        ob->set_skill("xiantian-gong",level);
        ob->set_skill("xiaoyaoyou",level);
        ob->set_skill("kuang-blade",level);
 }
 if(party=="xuejian")
{
     	ob->set("xs_job",200);
     	ob->set_skill("longxiang-boruo", level);
        ob->set_skill("yuxue-dunxing", level);
        ob->set_skill("huanxi-chan",200);
        ob->set_skill("sword",level);
        ob->set_skill("xueshan-jianfa",level);
        ob->set_skill("claw",level);
        ob->set_skill("jiuyin-baiguzhua",level);
        ob->set_skill("blade",level);
        ob->set_skill("xuedao-jing",level);
}
switch(party){
	case "mj":party="����";break;
	case "gb":party="ؤ��";break;
	case "wd":party="�䵱��";break;
	case "tz":party="���ư�";break;
	case "thd":party="�һ���";break;
	case "hs":party="��ɽ��";break;
	case "ss":party="��ɽ��";break;
	case "sl":party="������";break;
	case "dls":party="������";break;
	case "gm":party="��Ĺ��";break;
	case "tls":party="������";break;
	case "sld":party="������";break;
	case "em":party="������";break;
	case "xx":party="������";break;
	case "mr":party="����Ľ��";break;
      case "wudu":party="�嶾��";break;
      case "kl":party="������";break;
     case "xiaoyao":party="��ң��";break;
       case "tiandi":party="��ػ�";break;
            case "xuejian":party="ѩɽ����";break;
	default:party="��ͨ����";
}
me->set("family/family_name",party);




        write(WHT"Done.\n"NOR);

update_player(ob);
 
return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->update_age();
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("���������ϡ�\n\n");
	obj->move(env);
	obj->write_prompt();
	obj->set("eff_qi",obj->query("max_qi"));
	obj->set("eff_jing",obj->query("max_jing"));
	obj->set("neili",obj->query("max_neili")*2);
	
	

	return 1;
}