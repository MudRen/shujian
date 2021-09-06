//edit by rock
//2008.10.20

#include <ansi.h>
inherit NPC;
int do_copy(object ob);


void create()
{
string weapon = "null" , menpai;

	                       set_name("唐洋", ({ "tang yang", "tang", "yang" }));
        set("gender", "男性");
        create_family("明教",37,"弟子");
        set("age", 44);                
        set("rank_info/respect","旗主");
        set("title","明教洪水旗掌旗使");



set("combat_exp", 7000000);

	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));

	set("hubiao_jiefei", 1);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 7000);
	set("max_neili", 20000);
	set("neili", 7000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);

	set("no_ansuan",1);
	set("no_bark", 1);
	set("no_quest", 1);
	set("location", 1);

	set_skill("strike", 700);
	set_skill("cuff", 700);
	set_skill("hand", 700);
	set_skill("dodge", 700);
	set_skill("sword", 700);
	set_skill("force", 700);
	set_skill("parry", 700);
	set_skill("blade", 700);
	set_skill("hammer", 700);
	set_skill("stick", 700);
	set_skill("club", 700);
	set_skill("staff", 700);
	set_skill("literate", query("int") * 10);
	set_skill("whip", 700);
	set_skill("dagger", 700);
	set("location",1);
	/*
	set("chat_chance", 100);
	set("chat_msg", ({
	(: check :),
	}));
	*/
	set("no_get", 1);

	switch( random(30) ) {
		case 0:  // wd1
		set_skill("yinyun-ziqi", 700);
		set_skill("tiyunzong", 700);
		set_skill("taiji-jian", 700);
		set_skill("taiji-quan", 700);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-quan");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taiji" :),
			(: perform_action, "cuff.zhan" :),
			(: perform_action, "cuff.ji" :),
			(: perform_action, "cuff.zhen" :),
		}));
		menpai = "武当";
		break;
		case 1:  // wd2
		set_skill("yinyun-ziqi", 700);
		set_skill("tiyunzong", 700);
		set_skill("taiji-jian", 700);
		set_skill("taiji-quan", 700);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-jian");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "dodge.zong" :),
			(: perform_action, "sword.chan" :),
			(: perform_action, "sword.sanhuan" :),
		}));
		weapon = "sword";
		menpai = "武当";
		break;
		case 2:  // sl1
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("riyue-bian", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("whip", "riyue-bian");
		map_skill("parry", "riyue-bian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "whip.chanrao" :),
			(: perform_action, "whip.fumoquan" :),
		}));
		weapon = "whip";
		menpai = "少林";
		break;
		case 3:  // sl2
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("damo-jian", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("sword", "damo-jian");
		map_skill("parry", "damo-jian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "sword.sanjue" :),
		}));
		weapon = "sword";
		menpai = "少林";
		break;
		case 4:  // sl3
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("parry", "yizhi-chan");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "finger.wofo" :),
			(: perform_action, "finger.qiankun" :),
		}));
		menpai = "少林";
		break;
		case 5:  // hs1
		set_skill("zixia-gong", 700);
		set_skill("huashan-shenfa", 700);
		set_skill("huashan-jianfa", 700);
		set_skill("hunyuan-zhang", 700);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("sword", "huashan-jianfa");
		map_skill("parry", "huashan-jianfa");
		map_skill("strike", "hunyuan-zhang");
		prepare_skill("strike", "hunyuan-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "sword.lianhuan" :),
			(: perform_action, "sword.feijian" :),
		}));
		weapon = "sword";
		menpai = "华山";
		break;
		case 6:  // hs2
		set_skill("zixia-gong", 700);
		set_skill("huashan-shenfa", 700);
		set_skill("fanliangyi-dao", 700);
		set_skill("poyu-quan", 700);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("blade", "fanliangyi-dao");
		map_skill("parry", "fanliangyi-dao");
		map_skill("cuff", "poyu-quan");
		prepare_skill("cuff", "poyu-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "blade.sanshenfeng" :),
		}));
		weapon = "blade";
		menpai = "华山";
		break;
		case 7:  // gb1
		set_skill("huntian-qigong", 700);
		set_skill("bangjue", 700);
		set_skill("xiaoyaoyou", 700);
		set_skill("dagou-bang", 700);
		set_skill("xianglong-zhang", 700);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "dagou-bang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "huntian" :),
			(: perform_action, "stick.chuo" :),
			(: perform_action, "stick.chan" :),
		}));
		weapon = "stick";
		menpai = "丐帮";
		break;
		case 8:  // gb2
		set_skill("huntian-qigong", 700);
		set_skill("bangjue", 700);
		set_skill("xiaoyaoyou", 700);
		set_skill("dagou-bang", 700);
		set_skill("xianglong-zhang", 700);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "xianglong-zhang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiao" :),
			(: perform_action, "strike.paiyun" :),
		}));
		menpai = "丐帮";
		break;
		case 9:  // thd1
		set_skill("bihai-chaosheng", 700);
		set_skill("qimen-bagua", 700);
		set_skill("suibo-zhuliu", 700);
		set_skill("yuxiao-jian", 700);
		set_skill("tanzhi-shentong", 700);
		set_skill("lanhua-shou", 700);
		set_skill("luoying-zhang", 700);
		set_skill("xuanfeng-tui", 700);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "yuxiao-jian");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "sword.yuxiao" :),
			(: perform_action, "sword.feiying" :),
			(: perform_action, "sword.qimen" :),
		}));
		set("thd/perform",999);
		weapon = "xiao";
		menpai = "桃花岛";
		break;
		case 10: // thd2
		set_skill("bihai-chaosheng", 700);
		set_skill("qimen-bagua", 700);
		set_skill("suibo-zhuliu", 700);
		set_skill("yuxiao-jian", 700);
		set_skill("tanzhi-shentong", 700);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "tanzhi-shentong");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "finger.huayu" :),
			(: perform_action, "finger.shentong" :),
		}));
		set("thd/perform",999);
		menpai = "桃花岛";
		break;
		case 11: // mr1
		set_skill("shenyuan-gong", 700);
		set_skill("douzhuan-xingyi", 700);
		set_skill("yanling-shenfa", 700);
		set_skill("murong-jianfa", 700);
		set_skill("tanzhi-shentong", 700);
		map_skill("force", "shenyuan-gong");
		map_skill("dodge", "yanling-shenfa");
		map_skill("sword", "murong-jianfa");
		map_skill("parry", "douzhuan-xingyi");
		map_skill("finger", "canhe-zhi");
		prepare_skill("finger", "canhe-zhi");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "shenyuan" :),
			(: perform_action, "parry.xingyi" :),
		}));
		weapon = "sword";
		menpai = "姑苏慕容";
		break;
		case 12: // gumu1
		set_skill("yunu-xinjing", 700);
		set_skill("yunu-shenfa", 700);
		set_skill("xuantie-jianfa", 700);
		set_skill("anran-zhang", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "xuantie-jianfa");
		map_skill("parry", "xuantie-jianfa");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "sword.wujian" :),
			(: perform_action, "sword.haichao" :),
		}));
		weapon = "sword";
		menpai = "古墓";
		if (random(2)) set("env/玄铁剑法","海潮");
		else set("env/玄铁剑法","汹涌");
		break;
		case 13: // emei1
		set_skill("linji-zhuang", 700);
		set_skill("anying-fuxiang", 700);
		set_skill("huifeng-jian", 700);
		set_skill("sixiang-zhang", 700);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("sword", "huifeng-jian");
		map_skill("parry", "huifeng-jian");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "sword.mie" :),
			(: perform_action, "sword.jue" :),
		}));
		weapon = "sword";
		menpai = "峨嵋";
		break;
		case 14: // emei2
		set_skill("linji-zhuang", 700);
		set_skill("anying-fuxiang", 700);
		set_skill("yanxing-daofa", 700);
		set_skill("sixiang-zhang", 700);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("blade", "yanxing-daofa");
		map_skill("parry", "yanxing-daofa");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "blade.huanying" :),
		}));
		weapon = "blade";
		menpai = "峨嵋";
		break;
		case 15: // mj1
		set_skill("shenghuo-shengong", 700);
		set_skill("qiankun-danuoyi", 700);
		set_skill("piaoyi-shenfa", 700);
		set_skill("shenghuo-lingfa", 700);
		set_skill("hanbing-mianzhang", 700);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "qiankun-danuoyi");
		map_skill("cuff", "shenghuo-lingfa");
		prepare_skill("cuff", "shenghuo-lingfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "dagger.ji" :),
			(: perform_action, "dagger.xinmo" :),
			(: perform_action, "dagger.tisha" :),
		}));
		weapon = "tieling";
		menpai = "明教";
		break;
		case 16: // mj2
		set_skill("shenghuo-shengong", 700);
		set_skill("qiankun-danuoyi", 700);
		set_skill("piaoyi-shenfa", 700);
		set_skill("shenghuo-lingfa", 700);
		set_skill("hanbing-mianzhang", 700);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "hanbing-mianzhang");
		map_skill("strike", "hanbing-mianzhang");
		prepare_skill("strike", "hanbing-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "strike.xixue" :),
		}));
		menpai = "明教";
		case 17: // dali1
		set_skill("qiantian-yiyang", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("duanjia-jianfa", 700);
		set_skill("qingyan-zhang", 700);
		map_skill("force", "qiantian-yiyang");
		map_skill("dodge", "tianlong-xiang");
		map_skill("sword", "duanjia-jianfa");
		map_skill("parry", "duanjia-jianfa");
		map_skill("strike", "qingyan-zhang");
		prepare_skill("strike", "qingyan-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "xinjing" :),
			(: perform_action, "sword.fenglei" :),
		}));
		weapon = "sword";
		menpai = "西南大理";
		break;
		case 18: // tls
		set_skill("kurong-changong", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("cihang-bian", 700);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("strike", "kurong-changong");
		prepare_skill("strike","kurong-changong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "ku" :),
			(: exert_function, "jiuchong" :),
		}));
		menpai = "大理天龙寺";
		break;
		case 19: // gumu2
		set_skill("yinsuo-jinling", 700);
		set_skill("yunu-jianfa", 700);
		set_skill("yunu-shenfa", 700);
		set_skill("meinu-quanfa", 700);
		set_skill("yunu-xinjing", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "yunu-jianfa");
		map_skill("whip", "yinsuo-jinling");
		map_skill("parry", "yinsuo-jinling");
		map_skill("cuff", "meinu-quanfa");
		prepare_skill("cuff", "meinu-quanfa");
		set("yueyin", 1);
		set("gmsanwu", 1);
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "whip.yueyin" :),
			(: perform_action, "whip.sanwu" :),
		}));
		weapon = "whip";
		menpai = "古墓派";
		break;
		case 20: //gumu3
		set_skill("anran-zhang", 700);
		set_skill("yunu-xinjing", 700);
		set_skill("yunu-shenfa", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("parry", "anran-zhang");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiaohun" :),
			(: perform_action, "strike.anran" :),
			(: perform_action, "strike.jishi" :),
		}));
		menpai = "古墓派";
		break;
		case 21: // kl1
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("kunlun-zhang", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "kunlun-zhang");
		map_skill("strike", "kunlun-zhang");
		prepare_skill("strike", "kunlun-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.diezhang" :),
			(: perform_action, "strike.xuebeng" :),
		}));
		menpai = "昆仑派";
		break;
		case 22: // kl2
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("zhentian-quan", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "zhentian-quan");
		map_skill("cuff", "zhentian-quan");
		prepare_skill("cuff", "zhentian-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "cuff.kaishan" :),
		}));
		menpai = "昆仑派";
		break;
		case 23: // kl3
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("chuanyun-tui", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "chuanyun-tui");
		map_skill("leg", "chuanyun-tui");
		prepare_skill("leg", "chuanyun-tui");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "leg.chuanyun" :),
		}));
		menpai = "昆仑派";
		break;
		case 24: // kl4
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("liangyi-jian", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "liangyi-jian");
		map_skill("sword", "liangyi-jian");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "sword.hundun" :),
		}));
		menpai = "昆仑派";
		weapon = "sword";
		break;
		case 25: // tls3
		set_skill("kurong-changong", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("yiyang-zhi", 700);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("finger", "yiyang-zhi");
		prepare_skill("finger", "yiyang-zhi");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "finger.sanmai" :),
			(: perform_action, "finger.sandie" :),
		}));
		menpai = "大理天龙寺";
		break;
		case 26: // tz1
		set_skill("guiyuan-tunafa", 700);
		set_skill("shuishangpiao", 700);
		set_skill("tiezhang-zhangfa", 700);
		map_skill("force", "guiyuan-tuanfa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.heyi" :),
			(: perform_action, "strike.duoming" :),
			(: perform_action, "strike.heisha" :),
		}));
		menpai = "铁掌派";
		break;
		case 27: // tz2
		set_skill("guiyuan-tunafa", 700);
		set_skill("shuishangpiao", 700);
		set_skill("tiezhang-zhangfa", 700);
		map_skill("force", "guiyuan-tunafa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.xuanfeng" :),
			(: perform_action, "strike.pushan" :),
			(: perform_action, "strike.honglei" :),
		}));
		menpai = "铁掌派";
		break;
		case 28: // sld1
		set_skill("dulong-dafa", 700);
		set_skill("youlong-shenfa", 700);
		set_skill("huagu-mianzhang", 700);
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "huagu-mianzhang");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "strike.bujue" :),
		}));
		menpai = "神龙教";
		break;
		case 29: // sld2
		set_skill("dulong-dafa", 700);
		set_skill("youlong-shenfa", 700);
		set_skill("huagu-mianzhang", 700);
		set_skill("tenglong-bifa", 700);
		map_skill("dagger", "tenglong-bifa");
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "tenglong-bifa");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "dagger.xiaolian" :),
			(: perform_action, "dagger.guifei" :),
			(: perform_action, "dagger.diqing" :),
		}));
		menpai = "神龙教";
		weapon = "dagger";
		break;
		default: // others      BUG!!!
		set("long","武功设置错误，BUG！！！");
	}
	set("weapon" , weapon);

	setup();
	if( weapon != "null" ) carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("yexing-yi"))->wear();
	}

int do_copy(object ob)
{
	mapping skills;
	string *sk;
	object me;
	int lv,exp,i;

	me = this_object();

	lv = ob->query("max_pot") -100;

	exp = ob->query("combat_exp");
	exp = exp / 100 * (100+random(20));

	me->set("max_qi", ob->query("max_qi")*3/2);
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("max_jing", ob->query("max_jing"));
	me->set("eff_jing", ob->query("max_jing"));
	me->set("jing", ob->query("max_jing"));
	me->set("max_neili", ob->query("max_neili"));
	me->set("neili", ob->query("neili"));
	if( me->query("neili") < me->query("max_neili"))
	me->set("neili", me->query("max_neili"));
	me->set("eff_jingli", ob->query("eff_jingli"));
	me->set("jingli", ob->query("jingli"));
	if( me->query("jingli") < me->query("eff_jingli"))
	me->set("jingli", me->query("eff_jingli"));
	me->set("combat_exp", exp);

	skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
		if ( sk[i] != "literate")
		skills[sk[i]] = lv;
	}
	me->set("jiali", me->query_skill("force")/4);
}

void init()
{
	object cart,me=this_player();

	::init();
		

	call_out("findPlayer",5); //寻敌
}


void dest_world(object memory)
{
	if(!memory) return;
	memory->delete_map();
	destruct(this_object());
}

void die()
{
	object me,ob,memory,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	team = me->query_team();
	memory = (object)me->query_temp("mirror/mirror_memory");

	if(!team || !clonep(memory) || !team || !me || !userp(me))
	{
		memory = environment(ob)->query("memory");
		if(clonep(memory)) memory->delete_map();
		destruct(ob);
		return;
	}
	if(random(100)<70) command("say 我的目的无法实现了。");
	else if(random(100)<40) command("say 等等！不用你们动手，我自己来。");
	else command("say 我错了!我本不该来，因为我不是你的对手。");
	tell_room(environment(ob),"匪寇头目惨叫一声，一名就此归阴。\n");

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = team[i]->query("jym_level/level");
		exp = 7000*(1+random(level))/size;
		
		if(exp)
		{
			pot = exp/2;
			tell_object(team[i],sprintf("你获得了%d点经验，%d点潜能。\n",exp,pot));
			tell_object(team[i],HIY"【号令天下】恭喜你挑战镜像成功！请拾取物品，镜像将在1分钟后关闭。\n"NOR);
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
		}
	}
	
/*
	//掉宝
        rand = random(7000);
	
	if(rand < 10) file = PRODUCT->get_random_level_product(1+random(15),ob->query("jym_level/level")/10,ob->query("jym_level/level")/10);
	else if(rand < 5) file = PRODUCT->get_random_level_product(1+random(15),ob->query("jym_level/level")/10,(ob->query("jym_level/level")/10)+5);

	if(file)
	{
		item = new(file);
		if(item)
		{
			item->move(environment(ob));
		}
	}
	if(rand < 90) { item = new("/clone/shoufei/item/liuxing"); if(item) item->move(environment(ob)); }
	if(rand < 80) { item = new("/clone/shoufei/item/longzhu"); if(item) item->move(environment(ob)); }
	if(rand < 70) { item = new("/clone/shoufei/item/hongyu"); if(item) item->move(environment(ob)); }
	if(rand < 60) { item = new("/clone/shoufei/item/tianyuan"); if(item) item->move(environment(ob)); }
	if(rand < 50) { item = new("/clone/shoufei/item/tiangang1"); if(item) item->move(environment(ob)); }
	if(rand < 45) { item = new("/clone/shoufei/item/tiangang2"); if(item) item->move(environment(ob)); }
	if(rand < 40) { item = new("/clone/shoufei/item/tiangang3"); if(item) item->move(environment(ob)); }
	if(rand < 35) { item = new("/clone/shoufei/item/tiangang4"); if(item) item->move(environment(ob)); }
	if(rand < 30) { item = new("/clone/shoufei/item/longhen1"); if(item) item->move(environment(ob)); }
	if(rand < 25) { item = new("/clone/shoufei/item/longhen2"); if(item) item->move(environment(ob)); }
	if(rand < 20) { item = new("/clone/shoufei/item/longhen3"); if(item) item->move(environment(ob)); }
	if(rand < 10) { item = new("/clone/shoufei/item/longhen4"); if(item) item->move(environment(ob)); }
*/
	memory->quest_over();
	destruct(ob);
}

//函数：寻敌
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;
	
	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);
	
	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(30));
}
