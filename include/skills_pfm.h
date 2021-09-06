//common skills and pfm file skills_pfm.h
//created by campsun 2003/09/19
//ͨ�õ�skills���ú�pfm���ú���
//ʹ�÷�����copy_menpai(�������֣��ߵͼ��书���Ƿ�ʹ��������pfm�ĸ��ʣ�
//��һ������ͨ��������ã�����������ã������������Ϊ�գ���ʹ���ڶ���str_menpai�����ѡ��һ�����ɡ�
//�书�ĸߵ�ָ�����ɵĸ߼��书�͵ͼ��书֮�֡�
//�Ƿ�ʹ������ָ��������npc�Ƿ�ʹ������
//pfm�ĸ��ʣ����Ϊ0���򲻷�pfm
//ע1���������������ɶ��и߼��ͳ����Ŀ��ֻ���
//copy to /inclue/�� by campsun 2003/10/30
//ʹ�ø�.h�ļ�֮ǰ������inhert һ��npc����master

#ifndef _SKILL_PFM_
#define _SKILL_PFM_
#endif

int copy_menpai(string , int , int , int);
int set_skills_level(int);																			//�趨npc���书�ȼ����Զ��ų�һЩ���Ƶȼ����书
void copy_state();																					//����npc�����ɣ����һ����jing��qi�ӳ�	



void copy_state()
{
	object ob;
	mapping skl;
	int death;
	ob=this_object();
	skl = ob->query_skills();

		switch (ob->query("family/family_name")) {
			case "������":
				if (skl["xuantian-wuji"] > 400 ) {
					ob->add("max_jing", (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
					ob->add("max_qi", (skl["art"]/2-30)*(skl["xuantian-wuji"]/12)*3);
					break;
				}
				if (skl["art"] > 81) {
					ob->add("max_jing", (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
					ob->add("max_qi", (skl["art"]/2-30)*(skl["xuantian-wuji"]/15)*3);
				}
				break;
			case "������":
			case "������":
				if (skl["buddhism"] > 61)
					ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["force"]/10));
				if (skl["buddhism"] > 101)
					ob->add("max_qi",(skl["buddhism"]/2-40)*(skl["force"]/20)*3);
				break;
			case "���ư�":
				if (skl["tiezhang-xinfa"] > 61 ){
					ob->add("max_qi", (skl["tiezhang-xinfa"]/2-30)*(skl["guiyuan-tunafa"]/20)*3);
					ob->add("max_jing", (skl["tiezhang-xinfa"]/2-40)*(skl["guiyuan-tunafa"]/20));
				}
			case "������":
				if (skl["dacheng-fofa"] > 61)
					ob->add("max_jing",(skl["dacheng-fofa"]/2-30)*(skl["linji-zhuang"]/10));
				if (skl["dacheng-fofa"] > 101)
					ob->add("max_qi",(skl["dacheng-fofa"]/2-40)*(skl["linji-zhuang"]/20)*3);
				break;
			case "�һ���":
				if (skl["qimen-bagua"] > 61){
					ob->add("max_qi", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15)*3);
					ob->add("max_jing", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15));
				}
				break;
			case "�䵱��":
				if (skl["taoism"] > 61)
					ob->add("max_qi",(skl["taoism"]/2-30)*(skl["yinyun-ziqi"]/10)*3);
				if (skl["taoism"] > 121)
					ob->add("max_jing",(skl["taoism"]/2-50)*(skl["yinyun-ziqi"]/25));
				break;
			case "������":
				if (skl["poison"] > 61)
					ob->add("max_qi",(skl["poison"]/2-25)*(skl["huagong-dafa"]/10)*3);
				if (skl["poison"] > 121)
					ob->add("max_jing",(skl["poison"]/2-50)*(skl["huagong-dafa"]/20));
				break;
			case "����Ľ��":
			case "����":
				if (skl["force"] > 81)
					ob->add("max_qi",(skl["force"]/2-40)*15*3);
				if (skl["force"] > 151)
					ob->add("max_jing",(skl["force"]/2-40)*15);
				break;
			case "ؤ��":
				death = ob->query("death_times");
				if ( death > 100 ) death = 100;
				if ( death > 1){
					ob->add("max_qi", death * ob->query("con")*3);
					ob->add("max_jing", death * ob->query("con"));
				}
				if (skl["begging"] > 61)
					ob->add("max_qi",(skl["begging"]/2-30)*(skl["huntian-qigong"]/20)*3);
				break;
			case "������":
				if (skl["huanxi-chan"] > 61)
					ob->add("max_jing",(skl["huanxi-chan"]/2-30)*(skl["longxiang-boruo"]/10));
				if (skl["huanxi-chan"] > 121)
					ob->add("max_qi",(skl["huanxi-chan"]/2-50)*(skl["longxiang-boruo"]/40)*3);
				break;
			case "��Ĺ��":
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_qi",(skl["yunu-xinjing"]/2-40)*10*3);
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_jing",(skl["yunu-xinjing"]/2-40)*15);
				break;
			case "������":
                if (skl["shenlong-yaoli"] > 81 && skl["dulong-dafa"] > 81){
		   			ob->add("max_qi", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/16)*3);
					ob->add("max_jing", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/25));
	   			}
				break;
			case "��ɽ��":
				if (skl["songshan-jian"] > 51)
					ob->add("max_qi", skl["songshan-jian"]*3*3);
				if (skl["hanbing-zhenqi"] > 81)
					ob->add("max_jing",(skl["hanbing-zhenqi"]/2-40)*10);
				break;
			case "��ɽ��":
				if (skl["zhengqi-jue"] > 61 ){
					ob->add("max_qi", (skl["zhengqi-jue"]/2-30)*(skl["zixia-gong"]/20)*3);
					ob->add("max_jing", (skl["zhengqi-jue"]/2-30)*(skl["zixia-gong"]/20));
				}
				break;
			case "��ң��":
				if (skl["beiming-shengong"] > 61 ){
					ob->add("max_qi", (skl["taoism"]/2-30)*(skl["beiming-shengong"]/20)*3);
					ob->add("max_jing", (skl["taoism"]/2-30)*(skl["beiming-shengong"]/20));
				}
				break;
						case "���չ�":
				if (skl["bahuang-gong"] > 61 ){
					ob->add("max_qi", (skl["yangyanshu"]/2-30)*(skl["bahuang-gong"]/20)*3);
					ob->add("max_jing", (skl["yangyanshu"]/2-30)*(skl["bahuang-gong"]/20));
				}
				break;
							case "ȫ���":
				if (skl["xiantian-gong"] > 61 ){
					ob->add("max_qi", (skl["taoism"]/2-30)*(skl["xiantian-gong"]/20)*3);
					ob->add("max_jing", (skl["taoism"]/2-30)*(skl["xiantian-gong"]/20));
				}
				break;
							case "�������":
				if (skl["tianmo-jue"] > 61 ){
					ob->add("max_qi", (skl["tianmo-jue"]/2-30)*(skl["tianmo-gong"]/20)*3);
					ob->add("max_jing", (skl["tianmo-jue"]/2-30)*(skl["tianmo-gong"]/20));
				}
				break;
							case "ŷ������":
				if (skl["shexing-diaoshou"] > 61 ){
					ob->add("max_qi", (skl["poison"]/2-30)*(skl["shexing-diaoshou"]/20)*3);
					ob->add("max_jing", (skl["poison"]/2-30)*(skl["shexing-diaoshou"]/20));
				}
				break;
			default:
                                if( skl["hamagong"] >= 1 ){
					ob->add("max_qi", skl["hamagong"] * 5*3);
					ob->add("max_jing", skl["hamagong"] * 5);
				}
		}
	
	ob->add("max_qi", ob->query("max_neili") * ob->query("con") / 80);
	
	
}//end copy_state
int set_skills_level(int level)
{
	object me;
	mapping skills;
	string *sk;
	int i;
	string *str_skill_other = ({"taoism",						//�䵱����ѧ�ķ�
							"begging",						//ؤ��л�����
							"bangjue",						//ؤ��򹷰��ھ�
							"stealing",						//ؤ����ֿտ�
							"checking",						//ؤ�
							"zhenqijue",					//��ɽ��������
							"tiezhang-xinfa",				//���ƣ������ķ�
							"huanxi-chan",					//�����£���ϲ��
							"shenlong-yaoli",				//������������ҩ��
							"dacheng-fofa",					//���ң���˷�
							"qimen-bagua",					//�һ��������Ű���
							"buddhism",						//�����£����֣������ķ�
							"art",							//���أ������黭
							"daode-jing",					//���������¾�
							"literate",
							"poison",
							"medicine"
							});

	me=this_object();
	skills = me->query_skills();
    if (mapp(skills)) 
         	{
                sk = keys(skills);
                sk= sk - str_skill_other;
                for (i=0;i<sizeof(sk);i++)
                	skills[sk[i]] = level;
          	}
          	
          	
}//end set_skills_level  


nosave string u_weapon="";
nosave string nw_parry="";
nosave string w_parry="";
nosave string u_liumai="";
nosave string* u_ub_pfm=({});									//��ս��״̬��pfm
nosave string* u_f_pfm=({});
nosave string* u_w_pfm=({});
nosave string* u_pfm=({});										//���Ի������������мܣ������мܣ�pfm�б�				
nosave string* skill;	                                                                   //skill �б�	
nosave int in_level;
nosave string u_menpai="";
nosave string *in_menpai;
nosave mapping pmap;											//prepare���书				
nosave string *str_liumai =({"shaoze","guanchong","shangyang","shaochong","zhongchong","shaoshang"});
nosave int in_weapon;

#include <skills_pfm_set.h>

int copy_menpai(string *in_menpai2,int in_level2 ,int in_weapon2,int in_pfmrate)
{
	string *str_menpai = ({ "wd","hs",
							"ss","gm",
							"gb","tz",
							"dls","mr",
							"sld","xx",
							"em","mj",
							"thd","tls",
							"sl","kl","9y",
							"pxj","jsj","hmg",
							"rysj","qzj","ljg",
							"xy","oy","xxdf"
						});

	//string u_menpai="";	
	in_menpai = in_menpai2;
	in_weapon = in_weapon2;

	set_skill("literate",100);
	set_skill("poison",100);
	set_skill("medicine",100);								//���Ի��书��������	
	
	set_skill("force",500);
	set_skill("dodge",500);
	set_skill("parry",500);                                 //���Ի������ڹ������������������м�
	
	set_skill("cuff",500);
	set_skill("finger",500);
	set_skill("leg",500);
	set_skill("strike",500);
	set_skill("claw",500);
	set_skill("throwing",500);
	set_skill("hand",500);									//���Ի����������书
	
	set_skill("sword",500);
	set_skill("blade",500);
	set_skill("stick",500);
	set_skill("staff",500);
	set_skill("axe",500);
	set_skill("brush",500);
	set_skill("dagger",500);
	set_skill("club",500);
	set_skill("whip",500);									//���Ի����������书

	if(sizeof(in_menpai))
	u_menpai=in_menpai[random(sizeof(in_menpai))];
	else
	u_menpai=str_menpai[random(sizeof(str_menpai))];
	
	if(in_level2) in_level=1;							//
	
	copy_menpai2();
	///

//���һ���书��û�п����书 �����书�趨Ϊ����ȭ ̫��ȭ
if (nw_parry=="")
{
	switch(random(2))
	{
		case 0:
			set_skill("kongming-quan",500);                 //����ȭ
			set("zhou/jieyi",1);
			map_skill("cuff","kongming-quan");
			nw_parry="kongming-quan";
			prepare_skill("cuff", "kongming-quan");
			u_pfm = u_pfm + ({(: perform_action, "cuff.kong" :)});			//����ȭpfm����			
			u_pfm = u_pfm + ({(: perform_action, "cuff.ming" :)});			//��
			set("f_skill","kongming-quan");
		break;
		case 1:
			set_skill("taizu-quan",500);
			map_skill("cuff","taizu-quan");
			nw_parry="taizu-quan";
			prepare_skill("cuff","taizu-quan");
			set("f_skill","taizu-quan");
		break;
	}
}
//���һ���书��û�б����书 wuhu-duanmendao
if (w_parry=="")
{
	set_skill("wuhu-duanmendao",500);
	map_skill("blade","wuhu-duanmendao");
	w_parry="wuhu-duanmendao";
	u_weapon="blade";
	u_f_pfm = u_f_pfm + ({(: perform_action, "blade.duan" :)});        	
	set("f_w_skill","wuhu-duanmendao");

}
//װ���������趨ʹ�õ��м�	
if (in_weapon && u_weapon!=""){
	carry_object(BINGQI_D(u_weapon))->wield();
	map_skill("parry",w_parry);
}
else{
	map_skill("parry",nw_parry);
}
//�趨�Ƿ��pfm�Լ���pfm�ĸ���
if (in_pfmrate)
{
	set("chat_chance_combat", in_pfmrate);
	if(in_weapon)
		set("chat_msg_combat", u_f_pfm + u_w_pfm);
	else
		set("chat_msg_combat", u_f_pfm + u_pfm);	
	if (sizeof(u_ub_pfm)!=0)
	{
		set("chat_chance", in_pfmrate);
		set("chat_msg", u_ub_pfm);	
	}
	if (sizeof(query("chat_msg"))== 0)
		delete("chat_msg");
	if (sizeof(query("chat_msg_combat")) == 0)
		delete("chat_msg_combat");	
}

//��¼obejct���õĿ����мܺͱ����м��Լ�ʹ�õ�����������Ҫ�ı�ʱ���Ե���
set("u_pfm",u_pfm);
set("u_w_pfm",u_w_pfm);
set("u_f_pfm",u_f_pfm);
set("w_parry",w_parry);
set("nw_parry",nw_parry);
set("u_weapon",u_weapon);

return 1;
}
 
