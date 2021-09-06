// body guard ����
// by emnil@sj          2/9/2k
// Modify By River@SJ

inherit NPC;

#include <ansi.h>

void checkfight();
int do_copy(object target,int mode);
string ask_leave();

string *title1 = ({ "����", "����", "����", "����", "��ԭ","����","����","����","��ԭ","����","����","�ӱ�","����"});
string *title2 = ({ "��ͷ", "����", "��ͷ", "��Ժ", "����"});

void create()
{
	string weapon = "null" , menpai, title;
	mapping name;
	int i;

	i = random(4);

	title = title1[random(sizeof(title1))];
	title += title2[random(sizeof(title2))];

	name = RNAME_D->get_random_name(i);

	set_name(name["name"], name["id"] + ({ "guard" }));
	set("title", HIW+title+NOR);
	set("gender", (i==0?"Ů��":"����"));
	set("age", 20 + random(40));
	set("long", "����λ�������ݵı��ڣ�����׳ʵ��һ�������书���֣�\n");

	set("combat_exp", 5000000);
	set("meitude","peaceful");
	set("str", 27);
	set("int", 25+random(5));
	set("con", 30);
	set("dex", 31);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);
	set_temp("apply/armor", 50);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);

	set("no_ansuan",1);
	set("no_bark", 1);
//	set("no_quest", 1);
	set("location", 1);

	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("stick", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("literate", query("int") * 10);
	set_skill("whip", 500);
	set_skill("dagger", 500);

	set("inquiry", ([
		"����" : (: ask_leave :),
		"fight" : (: ask_leave :),
	]));
/*
	set("chat_chance", 11);
   set("chat_msg", ({
		(: random_move :)
	}));
*/
	switch( random(26) ) {
		case 0:  // wd1
			set_skill("yinyun-ziqi", 500);
			set_skill("tiyunzong", 500);
			set_skill("taiji-jian", 500);
			set_skill("taiji-quan", 500);
			map_skill("force", "yinyun-ziqi");
			map_skill("dodge", "tiyunzong");
			map_skill("sword", "taiji-jian");
			map_skill("parry", "taiji-quan");
			map_skill("cuff", "taiji-quan");
			prepare_skill("cuff", "taiji-quan");
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "taiji" :),
				(: perform_action, "cuff.zhan" :),
				(: perform_action, "cuff.ji" :),
				(: perform_action, "cuff.zhen" :),
			}));
			menpai = "�䵱";
			break;
		case 1:  // wd2
			set_skill("yinyun-ziqi", 500);
			set_skill("tiyunzong", 500);
			set_skill("taiji-jian", 500);
			set_skill("taiji-quan", 500);
			map_skill("force", "yinyun-ziqi");
			map_skill("dodge", "tiyunzong");
			map_skill("sword", "taiji-jian");
			map_skill("parry", "taiji-jian");
			map_skill("cuff", "taiji-quan");
			prepare_skill("cuff", "taiji-quan");
			set("chat_chance_combat", 25);
			set("chat_msg_combat", ({
				(: perform_action, "dodge.zong" :),
				(: perform_action, "sword.chan" :),
				(: perform_action, "sword.sanhuan" :),
			}));
			weapon = "sword";
			menpai = "�䵱";
			break;
		case 2:  // sl1
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("riyue-bian", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("whip", "riyue-bian");
			map_skill("parry", "riyue-bian");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");
			set("chat_chance_combat", 18);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "whip.chanrao" :),
				(: perform_action, "whip.fumoquan" :),
			}));
			weapon = "whip";
			menpai = "����";
			break;
		case 3:  // sl2
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("damo-jian", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("sword", "damo-jian");
			map_skill("parry", "damo-jian");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");
			set("chat_chance_combat", 25);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "sword.sanjue" :),
			}));
			weapon = "sword";
			menpai = "����";
			break;
		case 4:  // sl3
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("parry", "yizhi-chan");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");
			set("chat_chance_combat", 22);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "finger.wofo" :),
				(: perform_action, "finger.qiankun" :),
			}));
			menpai = "����";
			break;
		case 5:  // hs1
			set_skill("zixia-gong", 500);
			set_skill("huashan-shenfa", 500);
			set_skill("huashan-jianfa", 500);
			set_skill("hunyuan-zhang", 500);
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			map_skill("sword", "huashan-jianfa");
			map_skill("parry", "huashan-jianfa");
			map_skill("strike", "hunyuan-zhang");
			prepare_skill("strike", "hunyuan-zhang");
			set("chat_chance_combat", 22);
			set("chat_msg_combat", ({
				(: exert_function, "zixia" :),
				(: perform_action, "sword.lianhuan" :),
				(: perform_action, "sword.feijian" :),
			}));
			weapon = "sword";
			menpai = "��ɽ";
			break;
		case 6:  // hs2
			set_skill("zixia-gong", 500);
			set_skill("huashan-shenfa", 500);
			set_skill("fanliangyi-dao", 500);
			set_skill("poyu-quan", 500);
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			map_skill("blade", "fanliangyi-dao");
			map_skill("parry", "fanliangyi-dao");
			map_skill("cuff", "poyu-quan");
			prepare_skill("cuff", "poyu-quan");
			set("chat_chance_combat", 17);
			set("chat_msg_combat", ({
				(: exert_function, "zixia" :),
				(: perform_action, "blade.sanshenfeng" :),
			}));
			weapon = "blade";
			menpai = "��ɽ";
			break;
		case 7:  // gb1
			set_skill("huntian-qigong", 500);
			set_skill("bangjue", 500);
			set_skill("xiaoyaoyou", 500);
			set_skill("dagou-bang", 500);
			set_skill("xianglong-zhang", 500);
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			map_skill("stick", "dagou-bang");
			map_skill("parry", "dagou-bang");
			map_skill("strike", "xianglong-zhang");
			prepare_skill("strike", "xianglong-zhang");
			set("chat_chance_combat", 15);
			set("chat_msg_combat", ({
				(: exert_function, "huntian" :),
				(: perform_action, "stick.chuo" :),
				(: perform_action, "stick.chan" :),
			}));
			weapon = "stick";
			menpai = "ؤ��";
			break;
		case 8:  // gb2
			set_skill("huntian-qigong", 500);
			set_skill("bangjue", 500);
			set_skill("xiaoyaoyou", 500);
			set_skill("dagou-bang", 500);
			set_skill("xianglong-zhang", 500);
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			map_skill("stick", "dagou-bang");
			map_skill("parry", "xianglong-zhang");
			map_skill("strike", "xianglong-zhang");
			prepare_skill("strike", "xianglong-zhang");
			set("chat_chance_combat", 22);
			set("chat_msg_combat", ({
				(: perform_action, "strike.xiao" :),
				(: perform_action, "strike.paiyun" :),
			}));
			menpai = "ؤ��";
			break;
		case 9:  // thd1
			set_skill("bihai-chaosheng", 500);
			set_skill("qimen-bagua", 500);
			set_skill("suibo-zhuliu", 500);
			set_skill("yuxiao-jian", 500);
			set_skill("tanzhi-shentong", 500);
			set_skill("lanhua-shou", 500);
			set_skill("luoying-zhang", 500);
			set_skill("xuanfeng-tui", 500);
			map_skill("force", "bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
			map_skill("sword", "yuxiao-jian");
			map_skill("parry", "yuxiao-jian");
			map_skill("finger", "tanzhi-shentong");
			prepare_skill("finger", "tanzhi-shentong");
			set("chat_chance_combat", 14);
			set("chat_msg_combat", ({
				(: exert_function, "maze" :),
				(: perform_action, "sword.yuxiao" :),
				(: perform_action, "sword.feiying" :),
				(: perform_action, "sword.qimen" :),
			}));
			set("thd/perform",999);
			weapon = "xiao";
			menpai = "�һ���";
			break;
		case 10: // thd2
			set_skill("bihai-chaosheng", 500);
			set_skill("qimen-bagua", 500);
			set_skill("suibo-zhuliu", 500);
			set_skill("yuxiao-jian", 500);
			set_skill("tanzhi-shentong", 500);
			map_skill("force", "bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
			map_skill("sword", "yuxiao-jian");
			map_skill("parry", "tanzhi-shentong");
			map_skill("finger", "tanzhi-shentong");
			prepare_skill("finger", "tanzhi-shentong");
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "maze" :),
				(: perform_action, "finger.huayu" :),
				(: perform_action, "finger.shentong" :),
			}));
			set("thd/perform",999);
			menpai = "�һ���";
			break;
		case 11: // mr1
			set_skill("shenyuan-gong", 500);
			set_skill("douzhuan-xingyi", 500);
			set_skill("yanling-shenfa", 500);
			set_skill("murong-jianfa", 500);
			set_skill("tanzhi-shentong", 500);
			map_skill("force", "shenyuan-gong");
			map_skill("dodge", "yanling-shenfa");
			map_skill("sword", "murong-jianfa");
			map_skill("parry", "douzhuan-xingyi");
			map_skill("finger", "canhe-zhi");
			prepare_skill("finger", "canhe-zhi");
			set("chat_chance_combat", 26);
			set("chat_msg_combat", ({
				(: exert_function, "shenyuan" :),
				(: perform_action, "parry.xingyi" :),
			}));
			weapon = "sword";
			menpai = "����Ľ��";
			break;
		case 12: // gumu1
			set_skill("yunu-xinjing", 500);
			set_skill("yunu-shenfa", 500);
			set_skill("xuantie-jianfa", 500);
			set_skill("anran-zhang", 500);
			map_skill("force", "yunu-xinjing");
			map_skill("dodge", "yunu-shenfa");
			map_skill("sword", "xuantie-jianfa");
			map_skill("parry", "xuantie-jianfa");
			map_skill("strike", "anran-zhang");
			prepare_skill("strike", "anran-zhang");
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: perform_action, "sword.wujian" :),
				(: perform_action, "sword.haichao" :),
			}));
			weapon = "sword";
			menpai = "��Ĺ";
			if (random(2)) set("env/��������","����");
			else set("env/��������","��ӿ");
			break;
		case 13: // emei1
			set_skill("linji-zhuang", 500);
			set_skill("anying-fuxiang", 500);
			set_skill("huifeng-jian", 500);
			set_skill("sixiang-zhang", 500);
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
			menpai = "����";
			break;
		case 14: // emei2
			set_skill("linji-zhuang", 500);
			set_skill("anying-fuxiang", 500);
			set_skill("yanxing-daofa", 500);
			set_skill("sixiang-zhang", 500);
			map_skill("force", "linji-zhuang");
			map_skill("dodge", "anying-fuxiang");
			map_skill("blade", "yanxing-daofa");
			map_skill("parry", "yanxing-daofa");
			map_skill("strike", "sixiang-zhang");
			prepare_skill("strike", "sixiang-zhang");
			set("chat_chance_combat", 25);
			set("chat_msg_combat", ({
				(: exert_function, "wuwo" :),
				(: perform_action, "blade.huanying" :),
			}));
			weapon = "blade";
			menpai = "����";
			break;
		case 15: // mj1
			set_skill("shenghuo-shengong", 500);
			set_skill("qiankun-danuoyi", 500);
			set_skill("piaoyi-shenfa", 500);
			set_skill("shenghuo-lingfa", 500);
			set_skill("hanbing-mianzhang", 500);
			map_skill("force", "shenghuo-shengong");
			map_skill("dodge", "piaoyi-shenfa");
			map_skill("dagger", "shenghuo-lingfa");
			map_skill("parry", "qiankun-danuoyi");
			map_skill("cuff", "shenghuo-lingfa");
			prepare_skill("cuff", "shenghuo-lingfa");
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "yinfeng" :),
				(: perform_action, "dagger.ji" :),
				(: perform_action, "dagger.xinmo" :),
				(: perform_action, "dagger.tisha" :),
			}));
			weapon = "tieling";
			menpai = "����";
			break;
		case 16: // mj2
			set_skill("shenghuo-shengong", 500);
			set_skill("qiankun-danuoyi", 500);
			set_skill("piaoyi-shenfa", 500);
			set_skill("shenghuo-lingfa", 500);
			set_skill("hanbing-mianzhang", 500);
			map_skill("force", "shenghuo-shengong");
			map_skill("dodge", "piaoyi-shenfa");
			map_skill("dagger", "shenghuo-lingfa");
			map_skill("parry", "hanbing-mianzhang");
			map_skill("strike", "hanbing-mianzhang");
			prepare_skill("strike", "hanbing-mianzhang");
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "yinfeng" :),
				(: perform_action, "strike.xixue" :),
			}));
			menpai = "����";
		case 17: // dali1
			set_skill("qiantian-yiyang", 500);
			set_skill("tianlong-xiang", 500);
			set_skill("duanjia-jianfa", 500);
			set_skill("qingyan-zhang", 500);
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
			menpai = "���ϴ���";
			break;
		case 18: // tls
			set_skill("kurong-changong", 500);
			set_skill("tianlong-xiang", 500);
			set_skill("cihang-bian", 500);
			map_skill("force", "kurong-changong");
			map_skill("dodge", "tianlong-xiang");
			map_skill("parry", "kurong-changong");
			map_skill("strike", "kurong-changong");
			prepare_skill("strike","kurong-changong");
			set("chat_chance_combat", 26);
			set("chat_msg_combat", ({
				(: exert_function, "ku" :),
				(: exert_function, "jiuchong" :),
			}));
			menpai = "����������";
			break;
		case 19: // gumu2
			set_skill("yinsuo-jinling", 500);
			set_skill("yunu-jianfa", 500);
			set_skill("yunu-shenfa", 500);
			set_skill("meinu-quanfa", 500);
			set_skill("yunu-xinjing", 500);
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
			menpai = "��Ĺ��";
			break;
		case 20: //gumu3
			set_skill("anran-zhang", 500);
			set_skill("yunu-xinjing", 500);
			set_skill("yunu-shenfa", 500);
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
			menpai = "��Ĺ��";
			break;
		case 21: // kl1
			set_skill("xuantian-wuji", 500);
			set_skill("taxue-wuhen", 500);
			set_skill("kunlun-zhang", 500);
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			map_skill("parry", "kunlun-zhang");
			map_skill("strike", "kunlun-zhang");
			prepare_skill("strike", "kunlun-zhang");
			set("chat_chance_combat", 38);
			set("chat_msg_combat", ({
				(: perform_action, "strike.diezhang" :),
				(: perform_action, "strike.xuebeng" :),
			}));
			menpai = "������";
			break;
		case 22: // kl2
			set_skill("xuantian-wuji", 500);
			set_skill("taxue-wuhen", 500);
			set_skill("zhentian-quan", 500);
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			map_skill("parry", "zhentian-quan");
			map_skill("cuff", "zhentian-quan");
			prepare_skill("cuff", "zhentian-quan");
			set("chat_chance_combat", 45);
			set("chat_msg_combat", ({
				(: exert_function, "taxue" :),
				(: perform_action, "cuff.kaishan" :),
			}));
			menpai = "������";
			break;
		case 23: // kl3
			set_skill("xuantian-wuji", 500);
			set_skill("taxue-wuhen", 500);
			set_skill("chuanyun-tui", 500);
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			map_skill("parry", "chuanyun-tui");
			map_skill("leg", "chuanyun-tui");
			prepare_skill("leg", "chuanyun-tui");
			set("chat_chance_combat", 45);
			set("chat_msg_combat", ({
				(: exert_function, "taxue" :),
				(: perform_action, "leg.chuanyun" :),
			}));
			menpai = "������";
			break;
		case 24: // kl4
			set_skill("xuantian-wuji", 500);
			set_skill("taxue-wuhen", 500);
			set_skill("liangyi-jian", 500);
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			map_skill("parry", "liangyi-jian");
			map_skill("sword", "liangyi-jian");
			set("chat_chance_combat", 38);
			set("chat_msg_combat", ({
				(: perform_action, "sword.xunlei" :),
				(: perform_action, "sword.hundun" :),
			}));
			menpai = "������";
			weapon = "sword";
			break;			
		case 25: // tls3
			set_skill("kurong-changong", 500);
			set_skill("tianlong-xiang", 500);
			set_skill("yiyang-zhi", 500);
			map_skill("force", "kurong-changong");
			map_skill("dodge", "tianlong-xiang");
			map_skill("parry", "kurong-changong");
			map_skill("finger", "yiyang-zhi");
			prepare_skill("finger", "yiyang-zhi");
			set("chat_chance_combat", 40);
			set("chat_msg_combat", ({
				(: perform_action, "finger.sanmai" :),
				(: perform_action, "finger.sandie" :),
			}));
			menpai = "����������";
			break;
		default: // others      BUG!!!
			set("long","�书���ô���BUG������");
	}
	set("long" , query("long") + sprintf("��λ�����ƺ�����%s��\n",menpai) );
	set("weapon" , weapon);

	setup();
	if( weapon!="null" ) carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", random(99));

//	this_object()->start_call_out( (: call_other, this_object(), "display", this_object() :), 30);
	this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 1200);
}

void die()
{
	object me=this_object();

	if(objectp(me->query("beauty")))  (me->query("beauty"))->set("ok",1);
	::die();
}

int do_copy(object target,int mode)
{
	mapping skills;
	string *sk;
	object me,ob;
	int lv,exp,i,t;

	me = this_object();
	ob = target;
	if(mode) {
		t = 14+random(4);
		set("long",query("long")+"����ΰ���̫�ã�����������ر�Ӿ��������ģ���˵�������Ǵ��ڸ����أ�\n");
		add_money("gold", random(2));
	}
	else
		t = 10;

	lv = ob->query("max_pot") -100;
	lv = lv * t/10;
	exp = ob->query("combat_exp") *t/10;
	exp = exp * (100+random(20))/100;
me->set("no_party_job",1);
	me->set("max_qi", (int)ob->query("max_qi")*10/10*t/10 );
	me->set("eff_qi", (int)ob->query("max_qi")*10/10*t/10 );
	me->set("qi", (int)ob->query("max_qi")*10/10*t/10 );
	me->set("max_jing",(int)ob->query("max_jing"));
	me->set("eff_jing",(int)ob->query("max_jing"));
	me->set("jing",(int)ob->query("max_jing"));
	me->set("max_neili",(int)ob->query("max_neili") );
	me->set("neili",(int)ob->query("neili")*t/10 );
	if( me->query("neili") < me->query("max_neili") )
		me->set("neili",(int)me->query("max_neili") );
	me->set("max_jingli",(int)ob->query("max_jingli"));
	me->set("eff_jingli",(int)ob->query("eff_jingli"));
	me->set("jingli",(int)ob->query("jingli"));
	if( me->query("jingli") < me->query("eff_jingli") )
		me->set("jingli",(int)me->query("eff_jingli") );
	me->set("combat_exp",exp );

	skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if ( sk[i] != "literate")
			skills[sk[i]] = lv;
	}
	me->set("jiali",(int)me->query_skill("force")/4);
}
/*
void display()
{
        object me = this_object();

        if(!objectp(me->query("place"))) return;  // means BUG!!!
        me->move(me->query("place"));
}
*/
void dest()
{
	command("emote ����ææ���뿪�ˡ�");
	destruct(this_object());
}

string ask_leave()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if (!objectp (ob->query("xs/girl_ob")) || (ob->query("xs/girl_ob") != me->query("beauty")))
		return "�����й�������ˡ�����㡣";

	if(environment(me)->query("no_fight")) {
		random_move();
	}
	return "����������ְɣ�";
}

void kill_ob(object ob)
{
	object me = this_object();
	int qi;
/*
if( me->query("qi")<0 || me->query("max_qi")<0 ||me->query("eff_qi")<0) me->die();
*/
	command("!!!");
	if( !objectp (ob->query("xs/girl_ob"))
	 || (ob->query("xs/girl_ob") != me->query("beauty"))) {
		command("say ���Ӱ���");
		if( objectp(me->query("beauty")))
			(me->query("beauty"))->kill_ob(ob);
		me->remove_enemy(ob);
		ob->remove_killer(me);
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->clear_conditions_by_type("poison");
		return;
	}
	else
		command("say ���컯��Ҳ�����٣�");
	::kill_ob(ob);

	if( query("addqi")==0 && ob->query_temp("apply/damage") > 100 ) {
		qi = query("max_qi") * 3/2;
		if( qi < 3000) qi = qi*3/2;
		set("max_qi" , qi);
		set("eff_qi" , qi);
		set("qi" , qi);
		set("addqi" , 1);
	}
	call_out("checkfight", 2);
}

int accept_fight(object ob)
{
	object me = this_object();
/*
	if(( ob->query("id") == me->query("target")
	 && random(10) > 5
	 && !me->query("xs/accept_fight"))
	 || me->query("xs/no_accept_fight")){
		me->set("xs/no_accept_fight", 1);
		command("haha");
		command("say �����й�������ˡ�����㡣");
		return 0;
	}
	me->set("xs/accept_fight", 1);
*/
	if( ob->query("id") != me->query("target")) {
		command("haha");
		command("say �����й�������ˡ�����㡣");
		return 0;
	}
	else {
		if((me->query("eff_qi") < (me->query("max_qi")*2/3))
		|| (me->query("neili")<me->query("max_neili")/2))
		return 0;
		call_out("checkfight",2);

		if( query("addqi")==0 && ob->query_temp("apply/damage")>100 ) {
			int qi;
			qi = query("max_qi") *3/2;
			if(qi < 3000) qi = qi*3/2;
			set("max_qi" , qi);
			set("eff_qi" , qi);
			set("qi" , qi);
			set("addqi" , 1);
		}
		return 1;
	}
}

void checkfight()
{
	object me = this_object() , w;
	string weapon;

	if( !objectp(me) || !living(me) || !me->is_fighting())
		return;

	weapon = me->query("weapon");
	if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") ) {
		command("emote ���ó��ѱ�����");
		w = new(BINGQI_D(weapon));
		w->move(me);
		w->wield(me);
	}
	call_out("checkfight", 4);
}
