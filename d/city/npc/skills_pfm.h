//common skills and pfm file skills_pfm.h
//created by campsun 2003/09/19
//ͨ�õ�skills���ú�pfm���ú���
//ʹ�÷�����copy_menpai(�������֣��ߵͼ��书���Ƿ�ʹ��������pfm�ĸ��ʣ�
//��һ������ͨ��������ã�����������ã������������Ϊ�գ���ʹ���ڶ���str_menpai�����ѡ��һ�����ɡ�
//�书�ĸߵ�ָ�����ɵĸ߼��书�͵ͼ��书֮�֡�
//�Ƿ�ʹ������ָ��������npc�Ƿ�ʹ������
//pfm�ĸ��ʣ����Ϊ0���򲻷�pfm
//ע1���������������ɶ��и߼��ͳ����Ŀ��ֻ���

#include "r_name.h"

int copy_menpai(string , int , int , int);
int set_skills_level(int);			//�趨npc���书�ȼ����Զ��ų�һЩ���Ƶȼ����书
void copy_state();				//����npc�����ɣ����һ����jing��qi�ӳ�	
void get_npc_name();				//����npc�����ɣ����npc������

string *nick_first=({
HIB"�Ϻ�"NOR,HIY"ƽԭ"NOR,HIW"�ɶ�"NOR,HIG"����"NOR,RED"ƽ��"NOR,WHT"����"NOR,
HIB"����"NOR,HIW"Ʈѩ"NOR,YEL"���"NOR,HIY"����"NOR,MAG"���"NOR,HIR"Ϧ��"NOR,
HIY"����"NOR,});

string *nick_second=({
HIM"��"NOR,CYN"��"NOR,RED"��"NOR,WHT"ǹ"NOR,HIB"��"NOR,YEL"��"NOR,HIR"��"NOR,
CYN"��"NOR,HIB"��"NOR,HIY"��"NOR,HIR"����"NOR,HIG"��"NOR,WHT"��"NOR,HIB"��"NOR,
});

string create_nick()
{
	string nick1,nick2;
	nick1=nick_first[random(sizeof(nick_first))];
	nick2=nick_second[random(sizeof(nick_second))];
	if(random(5)>3)
		return nick1+"һ"+nick2;
	else
		return nick1+nick2;
}

void get_npc_name()
{
	mapping name;	
	object ob=this_object();
	int sex = random(3);
	int i;
	
	string *sl_fre_name=({"��","��","��","��","��","��","��","Բ"});									
	string *sl_fre_id=({"du","xuan","chen","hui","dao","qing","xu","yuan"});
	string *em_fre_name=({"��","��"});
	string *em_fre_id=({"mie","jing"});
	string *tls_fre_name=({"��","��"});
	string *tls_fre_id=({"ben","liao"});
	switch(ob->query("family/family_name"))
	{
		case "������":
			name=get_random_name(1,1);
			set("gender", "����");
			i=random(sizeof(sl_fre_name));
			set_name(sl_fre_name[i]+name["name"],({sl_fre_id[i]+" "+name["id"][0]}));
		break;
		case "��ü��":
			name=get_random_name(0,1);
			set("gender", "Ů��");
			i=random(sizeof(em_fre_name));
			set_name(em_fre_name[i]+name["name"],({em_fre_id[i]+" "+name["id"][0]}));			
		break;
		case "����Ľ��":
			name=get_random_name(sex,random(2)+1);
			set("gender", (sex?"����":"Ů��"));
			if(sizeof(name["id"])==1)
				set_name("Ľ��"+name["name"],({"murong "+name["id"][0]}));	
			else
				set_name("Ľ��"+name["name"],({"murong "+name["id"][1]+name["id"][2]}));        //�ر�ע�ͣ��������ɵ�ȫ�������ͣ����Ƿֿ����֣���ͬ
		break;
		case "�һ���":
			name=get_random_name(sex,2);
			set("gender", (sex?"����":"Ů��"));
			if(sizeof(name["id"])==1)
				set_name(name["name"]+"��",({name["id"][0]+" feng"}));	
			else
				set_name(name["name"]+"��",({name["id"][1]+name["id"][2]+" feng"}));
		break;
		case "������":	
			name=get_random_name(1,1);
			set("gender", "����");
			i=random(sizeof(tls_fre_name));
			set_name(tls_fre_name[i]+name["name"],({tls_fre_id[i]+" "+name["id"][0]}));
		break;		
		default:		
		set("gender", (sex?"����":"Ů��"));
		if(random(10))
    	name = get_random_name(sex,3);
    	else
    	name = get_random_name(sex,2);	
		set_name(name["name"], name["id"]);	
	}
	
	
}


void copy_state()
{
	object ob;
	mapping skl;
	ob=this_object();
	skl = ob->query_skills();

		switch (ob->query("family/family_name")) {
			case "������":
				if (skl["art"] > 81) {
					ob->add("max_jing",
							(skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
					ob->add("max_qi",
							(skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
				}
				break;
			case "������":
			case "������":
				if (skl["buddhism"] > 61)
					ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["force"]/10));
				if (skl["buddhism"] > 101)
					ob->add("max_qi",(skl["buddhism"]/2-40)*(skl["force"]/20));
				break;
			case "���ư�":
				if (skl["tiezhang-xinfa"] > 61 ){
					ob->add("max_qi", (skl["tiezhang-xinfa"]/2-30)*(skl["guiyuan-tunafa"]/20));
					ob->add("max_jing", (skl["tiezhang-xinfa"]/2-40)*(skl["guiyuan-tunafa"]/20));
				}
			case "������":
				if (skl["dacheng-fofa"] > 61)
					ob->add("max_jing",(skl["dacheng-fofa"]/2-30)*(skl["linji-zhuang"]/10));
				if (skl["dacheng-fofa"] > 101)
					ob->add("max_qi",(skl["dacheng-fofa"]/2-40)*(skl["linji-zhuang"]/20));
				break;
			case "�һ���":
				if (skl["qimen-bagua"] > 61){
					ob->add("max_qi", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15));
					ob->add("max_jing", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15));
				}
				break;
			case "�䵱��":
				if (skl["taoism"] > 61)
					ob->add("max_qi",(skl["taoism"]/2-30)*(skl["yinyun-ziqi"]/10));
				if (skl["taoism"] > 121)
					ob->add("max_jing",(skl["taoism"]/2-50)*(skl["yinyun-ziqi"]/25));
				break;
			case "������":
				if (skl["poison"] > 61)
					ob->add("max_qi",(skl["poison"]/2-25)*(skl["huagong-dafa"]/10));
				if (skl["poison"] > 121)
					ob->add("max_jing",(skl["poison"]/2-50)*(skl["huagong-dafa"]/20));
				break;
			case "����Ľ��":
			case "����":
				if (skl["force"] > 81)
					ob->add("max_qi",(skl["force"]/2-40)*15);
				if (skl["force"] > 151)
					ob->add("max_jing",(skl["force"]/2-40)*15);
				break;
			case "ؤ��":
				if (ob->query("death_times") > 1){
					ob->add("max_qi", ob->query("death_times") * ob->query("con"));
					ob->add("max_jing", ob->query("death_times") * ob->query("con"));
				}
				if (skl["begging"] > 61)
					ob->add("max_qi",(skl["begging"]/2-30)*(skl["huntian-qigong"]/20));
				break;
			case "������":
				if (skl["huanxi-chan"] > 61)
					ob->add("max_jing",(skl["huanxi-chan"]/2-30)*(skl["longxiang-boruo"]/10));
				if (skl["huanxi-chan"] > 121)
					ob->add("max_qi",(skl["huanxi-chan"]/2-50)*(skl["longxiang-boruo"]/40));
				break;
			case "��Ĺ��":
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_qi",(skl["yunu-xinjing"]/2-40)*10);
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_jing",(skl["yunu-xinjing"]/2-40)*15);
				break;
			case "������":
	     			if (skl["shenlong-yaoli"] > 51 && skl["dulong-dafa"] > 81){
		   			ob->add("max_qi", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/16));
					ob->add("max_jing", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/25));
	   			}
				break;
			case "��ɽ��":
				if (skl["songshan-jian"] > 51)
					ob->add("max_qi", skl["songshan-jian"]*3);
				if (skl["hanbing-zhenqi"] > 81)
					ob->add("max_jing",(skl["hanbing-zhenqi"]/2-40)*10);
				break;
			case "��ɽ��":
				if (skl["zhengqi-jue"] > 61 ){
					ob->add("max_qi", (skl["zhengqi-jue"]/2-30)*(skl["zixia-gong"]/20));
					ob->add("max_jing", (skl["zhengqi-jue"]/2-30)*(skl["zixia-gong"]/20));
				}
				break;
			default:
				if( skl["hamagong"] ){
					ob->add("max_qi", skl["hamagong"] * 5);
					ob->add("max_jing", skl["hamagong"] * 5);
				}
		}
	
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
								 


int copy_menpai(string *in_menpai,int in_level ,int in_weapon,int in_pfmrate)
{
	string *str_menpai = ({ "wd","hs",
							"ss","gm",
							"gb","tz",
							"dls","mr",
							"sld","xx",
							"em","mj",
							"thd","tls",
							"sl","kl","9y"
						});

	string *str_liumai =({"shaoze","guanchong","shangyang","shaochong","zhongchong","shaoshang"});
	
	string u_weapon="";
	string u_menpai="";
	string nw_parry="";
	string w_parry="";
	string u_liumai="";
	string* u_pfm=({});										//���Ի������������мܣ������мܣ�pfm�б�				
	string* skill;											//skill �б�	

	mapping pmap;											//prepare���书				

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
	
	if(in_level) in_level=1;								//
	
	switch(u_menpai)
	{
		case "wd":											//�趨�䵱���书
			set("family/family_name","�䵱��");
			set_skill("yinyun-ziqi",500);					//�䵱�ڹ���������
			set_skill("tiyunzong",500);						//�䵱�Ṧ: ������
			set_skill("taoism",200);                        //�䵱�����ѧ�ķ�
			map_skill("force", "yinyun-ziqi");              
			map_skill("dodge", "tiyunzong");
			u_pfm=u_pfm + ({(: exert_function, "yinyun" :)});             //������pfm:���ھ�
			u_pfm=u_pfm + ({(: exert_function, "taiji" :)});             //̫��
			u_pfm=u_pfm + ({(: perform_action, "dodge.zong" :)});         //������pfm:��   
			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("wudang-quan",500);                 //�䵱�ͼ����֣��䵱��ȭ
							map_skill("cuff","wudang-quan");
							nw_parry="wudang-quan";
							prepare_skill("cuff", "wudang-quan");
							set("f_skill","wudang-quan");
						break;
						case 1:
							set_skill("zhenshan-mianzhang",500);          //�䵱�ͼ����֣���ɽ���� 
							map_skill("strike","zhenshan-mianzhang");
							nw_parry="zhenshan-mianzhang";
							prepare_skill("strike","zhenshan-mianzhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.bingdi" :)});  //��ɽ����pfm:��������
							set("f_skill","zhenshan-mianzhang");
						break;
						case 2:
							set_skill("juehu-shou",500);          
							map_skill("hand","juehu-shou");
							nw_parry="juehu-shou";
							prepare_skill("hand","juehu-shou");
							set("f_skill","juehu-shou");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("xuanxu-daofa",500);                          //�䵱�ͼ����������鵶��
							map_skill("blade","xuanxu-daofa");
							w_parry="xuanxu-daofa";
							set("f_w_skill","xuanxu-daofa");
							u_weapon="blade";
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("taiji-quan",500);                      	         	   //�䵱�߼����֣�̫��ȭ
							map_skill("cuff","taiji-quan");
							nw_parry="taiji-quan";
							prepare_skill("cuff","taiji-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.ji" :)});				//̫��ȭpfm:��
							u_pfm = u_pfm + ({(: perform_action, "cuff.zhannian" :)});			//ճ�
							u_pfm = u_pfm + ({(: perform_action, "cuff.zhen" :)});				//��
							u_pfm = u_pfm + ({(: perform_action, "cuff.luanhuan" :)});			//�һ���
							u_pfm = u_pfm + ({(: perform_action, "cuff.yinyang" :)});			//������
							u_pfm = u_pfm + ({(: perform_action, "cuff.gangrou" :)});			//�����
							u_pfm = u_pfm + ({(: perform_action, "cuff.dongjing" :)});			//������
							u_pfm = u_pfm + ({(: perform_action, "cuff.an" :)});				//��
                                                  u_pfm = u_pfm + ({(: perform_action, "cuff.taiji" :)});                           //̫��
							set("f_skill","taiji-quan");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("taiji-jian",500);										//�䵱�߼�������̫����
							map_skill("sword","taiji-jian");
							w_parry="taiji-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.chan" :)});				//̫����pfm����
							u_pfm = u_pfm + ({(: perform_action, "sword.sanhuan" :)});			//��������
							u_pfm = u_pfm + ({(: perform_action, "sword.lian" :)});				//��
							set("wd/raozhi",1);
							u_pfm = u_pfm + ({(: perform_action, "sword.raozhi" :)});			//��ָ�ὣ
//							u_pfm = u_pfm + ({(: perform_action, "sword.tongshou" :)});			//���ͬ��
							u_weapon="sword";
							set("f_w_skill","taiji-jian");
						break;
					}					
				break;	
				}
			break;//end case wd
		case "ss":												//�趨��ɽ�书
			set("family/family_name","��ɽ��");
			set_skill("hanbing-zhenqi",500);					//��ɽ�ڹ�����������			
			set_skill("zhongyuefeng",500);						//��ɽ�Ṧ��������
			map_skill("force", "hanbing-zhenqi");
			map_skill("dodge", "zhongyuefeng");
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //��������pfm������
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //�ۺ�
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("songyang-shou",500);                             //��ɽ�ͼ����֣�������
							map_skill("hand","songyang-shou");
							nw_parry="songyang-shou";
							prepare_skill("hand", "songyang-shou");
							u_pfm=u_pfm + ({(: perform_action, "hand.junji" :)});        //������pfm������
							u_pfm=u_pfm + ({(: perform_action, "hand.yinyang" :)});      //����
							set("f_skill","songyang-shou");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("songyang-bian",500);                               //��ɽ�ͼ�������������
							map_skill("whip","songyang-bian");
							w_parry="songyang-bian";
							u_pfm=u_pfm + ({(: perform_action, "whip.luan" :)});          //������pfm����
							u_weapon="whip";
							set("f_w_skill","songyang-bian");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("hanbing-shenzhang",500);								//��ɽ�߼����֣���������		
							map_skill("strike","hanbing-shenzhang");
							nw_parry="hanbing-shenzhang";
							prepare_skill("strike","hanbing-shenzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.hanbing" :)});     //��������pfm������
							set("f_skill","hanbing-shenzhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("songshan-jian",500);										//��ɽ�߼���������ɽ����
							map_skill("sword","songshan-jian");
							w_parry="songshan-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.feiwu" :)});        	//��ɽ����pfm������
							u_pfm = u_pfm + ({(: perform_action, "sword.leiting" :)});			//����һ��
							u_pfm = u_pfm + ({(: perform_action, "sword.longfeng" :)});			//����	
							u_pfm = u_pfm + ({(: perform_action, "sword.songyang" :)});			//����
							u_weapon="sword";
							set("f_w_skill","songshan-jian");
						break;
					}					
				break;	
				}
			break;//end case ss			
		case "gb":                                                      //�趨ؤ���书
			set("family/family_name","ؤ��");
			set_skill("huntian-qigong",500);							//ؤ���ڹ�������һ����
			set_skill("xiaoyaoyou",500);								//ؤ���Ṧ����ң��	
			set_skill("begging",200);			
			set("death_times",50);								
			set_skill("bangjue",200);
			set_skill("stealing",200);
			set_skill("checking",200);									//ؤ�����begging��bangjue��stealing��checking		
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			u_pfm=u_pfm + ({(: exert_function, "powerup" :)});          //��������pfm��powerup
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("lianhua-zhang",500);				//ؤ��ͼ����֣�������
							map_skill("strike","lianhua-zhang");
							nw_parry="lianhua-zhang";
							prepare_skill("strike", "lianhua-zhang");
							set("f_skill","lianhua-zhang");
						break;
						case 1:
							set_skill("suohou-shou",500);              //ؤ��ͼ����֣�������
							map_skill("hand","suohou-shou");
							nw_parry="suohou-shou";
							prepare_skill("hand", "suohou-shou");
							set("f_skill","suohou-shou");
						break;
							

					}
					switch(random(3))
					{
						case 0:
							set_skill("huifeng-bian",500);                                //ؤ��ͼ��������ط��
							map_skill("whip","huifeng-bian");
							w_parry="huifeng-bian";
							u_pfm=u_pfm + ({(: perform_action, "whip.huixuan" :)});       //�ط��pfm���ط�
							u_weapon="whip";
							set("f_w_skill","huifeng-bian");
						break;
						case 1:
							set_skill("liuhe-daofa",500);								  //ؤ��ͼ���������������				
							map_skill("blade","liuhe-daofa");
							w_parry="liuhe-daofa";
							u_pfm=u_pfm + ({(: perform_action, "blade.sancai" :)});       //��������pfm����������	
							u_weapon="blade";
							set("f_w_skill","liuhe-daofa");
						break;
						case 2:
							set_skill("fengmo-zhang",500);								  //ؤ��ͼ���������ħ��
							set("shen",-5000000);
							map_skill("staff","fengmo-zhang");
							w_parry="fengmo-zhang";
							u_weapon="staff";
							u_pfm=u_pfm + ({(: perform_action, "staff.feizhi" :)});       //��������pfm����������	
							set("f_w_skill","fengmo-zhang");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("xianglong-zhang",500);								//ؤ��߼����֣�������
							map_skill("strike","xianglong-zhang");
							nw_parry="xianglong-zhang";
							prepare_skill("strike","xianglong-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.paiyun" :)});         //������pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.xiao" :)});		//Х
							u_pfm = u_pfm + ({(: perform_action, "strike.kanglong" :)});	//�����޻�
							set("xlz/hang",1);              								//������������
							set("f_skill","xianglong-zhang");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("dagou-bang",500);									//ؤ��߼��������򹷰���
							set_skill("dagou-bang",500);
							map_skill("stick","dagou-bang");
							w_parry="dagou-bang";
							u_pfm = u_pfm + ({(: perform_action, "stick.chan" :)});       	//�򹷰���pfm����
							u_pfm = u_pfm + ({(: perform_action, "stick.chuo" :)});			//��
							u_pfm = u_pfm + ({(: perform_action, "stick.shuangjue" :)});	//����˫��
							u_pfm = u_pfm + ({(: perform_action, "stick.tiao" :)});			//��
							u_pfm = u_pfm + ({(: perform_action, "stick.zhuan" :)});		//ת
							u_pfm = u_pfm + ({(: perform_action, "stick.wugou" :)});		//�����޹�
							u_weapon="stick";
							set("f_w_skill","dagou-bang");
						break;
					}					
				break;	
				}
			break;//end case gb		
		case "hs":                                                      //�趨��ɽ�书
			set("family/family_name","��ɽ��");
			set_skill("zixia-gong",500);								//��ɽ�ڹ�����ϼ��
			set_skill("huashan-shenfa",500);							//��ɽ�Ṧ����ɽ��	
			set_skill("zhengqi-jue",200);								//��ɽ���������			
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "zixia" :)});            //��ϼ��pfm��zixia    
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("poyu-quan",500);				//��ɽ�ͼ����֣�����ȭ
							map_skill("cuff","poyu-quan");
							nw_parry="poyu-quan";
							prepare_skill("cuff", "poyu-quan");
							set("f_skill","poyu-quan");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("fanliangyi-dao",500);                              //��ɽ�ͼ������������ǵ���
							map_skill("blade","fanliangyi-dao");
							w_parry="fanliangyi-dao";
							u_pfm=u_pfm + ({(: perform_action, "blade.sanshenfeng" :)});       //�����ǵ���pfm�����������
							u_weapon="blade";
							set("f_w_skill","fanliangyi-dao");
						break;
						case 1:
							set_skill("chongling-jian",500);                              //��ɽ�ͼ����������齣��
							map_skill("sword","chongling-jian");
							w_parry="chongling-jian";
//							u_pfm=u_pfm + ({(: perform_action, "sword.hebi" :)});       //���齣��pfm���ϱ�
							u_weapon="sword";
							set("f_w_skill","chongling-jian");
						break;			
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("hunyuan-zhang",500);				//��ɽ�ͼ����֣���Ԫ��
							map_skill("strike","hunyuan-zhang");
							nw_parry="hunyuan-zhang";
							prepare_skill("strike", "hunyuan-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.wuji" :)});       //��Ԫ��pfm����Ԫ�޼�
							set("f_skill","hunyuan-zhang");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("huashan-jianfa",500);								//��ɽ�߼���������ɽ����
							map_skill("sword","huashan-jianfa");
							w_parry="huashan-jianfa";
							u_pfm = u_pfm + ({(: perform_action, "sword.feijian" :)});     	//��ɽ����pfm���ɽ�
							u_pfm = u_pfm + ({(: perform_action, "sword.junzi" :)});		//����
							u_pfm = u_pfm + ({(: perform_action, "sword.kuaijian" :)});		//�콣
							u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});		//����
							u_pfm = u_pfm + ({(: perform_action, "sword.sanqingfeng" :)});	//�����
							u_pfm = u_pfm + ({(: perform_action, "sword.shijiushi" :)});	//ʮ��ʽ
							u_pfm = u_pfm + ({(: perform_action, "sword.shunv" :)});		//��Ů
							u_pfm = u_pfm + ({(: perform_action, "sword.wushuang" :)});		//��˫
							u_pfm = u_pfm + ({(: perform_action, "sword.xiyi" :)});			//ϣ��
							u_pfm = u_pfm + ({(: perform_action, "sword.yangwu" :)});		//����
							u_weapon="sword";
							set("f_w_skill","huashan-jianfa");
						break;
						case 1:
							set_skill("dugu-jiujian",500);								//��ɽ�߼����������¾Ž�
							map_skill("dodge","dugu-jiujian");
							map_skill("sword","dugu-jiujian");
							w_parry="dugu-jiujian";
							u_pfm = u_pfm + ({(: perform_action, "sword.kuangfeng" :)});    //���¾Ž�pfm�����
							u_pfm = u_pfm + ({(: perform_action, "sword.pobian" :)});		
							u_pfm = u_pfm + ({(: perform_action, "sword.pojian" :)});		
							u_pfm = u_pfm + ({(: perform_action, "sword.pozhang" :)});		
							u_pfm = u_pfm + ({(: perform_action, "sword.poqi" :)});	
							u_pfm = u_pfm + ({(: perform_action, "sword.poqiang" :)});	
							u_pfm = u_pfm + ({(: perform_action, "sword.posuo" :)});		
							u_pfm = u_pfm + ({(: perform_action, "sword.zongjue" :)});		//�ܾ�
							u_weapon="sword";
							set("f_w_skill","dugu-jiujian");
						break;
					}					
				break;	
				}
			break;//end case hs
		case "tz":												//�趨�����书
			set("family/family_name","���ư�");
			set_skill("guiyuan-tunafa",500);					//�����ڹ�����Ԫ���ɷ�			
			set_skill("shuishangpiao",500);						//�����Ṧ��ˮ��Ư
			set_skill("tiezhang-xinfa",200);					//������������ķ�
			map_skill("force", "guiyuan-tunafa");
			map_skill("dodge", "shuishangpiao");
			u_pfm=u_pfm + ({(: exert_function, "focus" :)});          //��������pfm��focus
			u_pfm=u_pfm + ({(: perform_action, "dodge.piao" :)});     //ˮ��Ưpfm:Ư
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("tiezhang-zhangfa",500);								//���Ƹ߼����֣������Ʒ�		
							map_skill("strike","tiezhang-zhangfa");							//tz �޵ͼ����֣����Եͼ�����Ҳ�������Ʒ�
							nw_parry="tiezhang-zhangfa";
							prepare_skill("strike","tiezhang-zhangfa");
							u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //�����Ʒ�pfm��������צ
							u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //�����Ʒ�pfm���� ɰ ��
							u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //�����Ʒ�pfm��������һ
							u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //�����Ʒ�pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //�����Ʒ�pfm����    ��
							u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //�����Ʒ�pfm�������̸�
							u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //�����Ʒ�pfm���������
							u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //�����Ʒ�pfm�������Ƶ�
							u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //�����Ʒ�pfm������
							set("f_skill","tiezhang-zhangfa");
						break;
					}				
					switch(random(2))
					{
						case 0:
							set_skill("liuye-daofa",500);                               //���Ƶͼ���������Ҷ����
							map_skill("blade","liuye-daofa");
							w_parry="liuye-daofa";
							u_pfm=u_pfm + ({(: perform_action, "blade.daozhang" :)});   //��Ҷ����pfm������
							u_weapon="blade";											//��Ҫ�����Ʒ�Ϊ�мܣ�����prepare
							set("f_w_skill","liuye-daofa");
						break;
						case 1:
							set_skill("yingou-bifa",500);                               //���Ƶͼ������������ʷ�
							map_skill("brush","yingou-bifa");
							w_parry="yingou-bifa";
							u_pfm=u_pfm + ({(: perform_action, "brush.caoshu" :)});  	//�����ʷ�pfm������
							u_pfm=u_pfm + ({(: perform_action, "brush.kaishu" :)});  	//�����ʷ�pfm������
							u_pfm=u_pfm + ({(: perform_action, "brush.shigu" :)});  	//�����ʷ�pfm������
							u_weapon="brush";
							set("f_w_skill","yingou-bifa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("tiezhang-zhangfa",500);								//���Ƹ߼����֣������Ʒ�		
							map_skill("strike","tiezhang-zhangfa");
							nw_parry="tiezhang-zhangfa";
							prepare_skill("strike","tiezhang-zhangfa");
							u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //�����Ʒ�pfm��������צ
							u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //�����Ʒ�pfm���� ɰ ��
							u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //�����Ʒ�pfm��������һ
							u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //�����Ʒ�pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //�����Ʒ�pfm����    ��
							u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //�����Ʒ�pfm�������̸�
							u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //�����Ʒ�pfm���������
							u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //�����Ʒ�pfm�������Ƶ�
							u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //�����Ʒ�pfm������
							set("f_skill","tiezhang-zhangfa");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("lietian-fu",500);                               //���Ƹ߼����������츫
							map_skill("axe","lietian-fu");
							w_parry="lietian-fu";
							u_pfm=u_pfm + ({(: perform_action, "axe.lihun" :)});  		//���츫pfm�����
							u_weapon="axe";
							set("f_w_skill","lietian-fu");
						break;
					}					
				break;	
				}
			break;//end case tz
			
		case "dls":												//�趨�������书
			set("family/family_name","������");
			set_skill("longxiang-boruo",500);					//�������ڹ������������			
			set_skill("yuxue-dunxing",500);						//�������Ṧ����ѩ����
			set_skill("huanxi-chan",200);						//�����������ϲ��
			map_skill("force", "longxiang-boruo");
			map_skill("dodge", "yuxue-dunxing");
			u_pfm=u_pfm + ({(: exert_function, "longxiang" :)});   //���������pfm������
			u_pfm=u_pfm + ({(: exert_function, "shield" :)});      //����
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("dashou-yin",500);                             //�����µͼ����֣�����ӡ
							map_skill("hand","dashou-yin");
							nw_parry="dashou-yin";
							prepare_skill("hand", "dashou-yin");
							u_pfm=u_pfm + ({(: perform_action, "hand.tianyin" :)});  //����ӡpfm����������ӡ
							set("f_skill","dashou-yin");
						break;
						case 1:
							set_skill("tianwang-zhua",500);                             //�����µͼ����֣�����ӡ
							map_skill("claw","tianwang-zhua");
							nw_parry="tianwang-zhua";
							prepare_skill("claw", "tianwang-zhua");
							set("f_skill","tianwang-zhua");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("wushang-dali",500);                               //�����µͼ����������ϴ�����
							map_skill("staff","wushang-dali");
							w_parry="wushang-dali";
							u_weapon="staff";
							set("f_w_skill","wushang-dali");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("huoyan-dao",500);								//�����¸߼����֣����浶		
							map_skill("strike","huoyan-dao");
							nw_parry="huoyan-dao";
							prepare_skill("strike","huoyan-dao");
							u_pfm = u_pfm + ({(: perform_action, "strike.fen" :)});     //���浶pfm����
							set("f_skill","huoyan-dao");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("xuedao-jing",500);										//�����¸߼�������Ѫ����
							map_skill("blade","xuedao-jing");
							w_parry="xuedao-jing";
							set("env/jixue",random(5)+1);                                       //pfm ��Ѫ��������
							u_pfm = u_pfm + ({(: perform_action, "blade.jixue" :)});        	//pfm ��Ѫ
							u_pfm = u_pfm + ({(: perform_action, "blade.shendao" :)});			//�񵶴���
							u_weapon="blade";
							set("f_w_skill","xuedao-jing");
						break;
						case 1:
							set_skill("xiangfu-lun",500);										//�����¸߼�������������
							map_skill("hammer","xiangfu-lun");
							w_parry="xiangfu-lun";
							u_pfm = u_pfm + ({(: perform_action, "hammer.wushuai" :)});        	//������˥
							u_pfm = u_pfm + ({(: perform_action, "hammer.dazhuan" :)});			//��ת
							u_weapon="hammer";
							set("f_w_skill","xiangfu-lun");
						break;
					}					
				break;	
				}
			break;//end case dls				
		case "gm":												//�趨��Ĺ�书
			set("family/family_name","��Ĺ��");
			set_skill("yunu-xinjing",500);						//��Ĺ�ڹ�����Ů�ľ�			
			set_skill("yunu-shenfa",500);						//��Ĺ�Ṧ����Ů��
			map_skill("force", "yunu-xinjing");
			map_skill("dodge", "yunu-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});  //��Ů�ľ�pfm��xinjing
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("tianluo-diwang",500);                             //��Ĺ�ͼ����֣����޵���ʽ
							map_skill("strike","tianluo-diwang");
							nw_parry="tianluo-diwang";
							prepare_skill("strike", "tianluo-diwang");
							set("f_skill","tianluo-diwang");
						break;
						case 1:
							set_skill("meinu-quanfa",500);                          		 //��Ĺ�ͼ����֣���Ůȭ��
							map_skill("cuff","meinu-quanfa");
							nw_parry="meinu-quanfa";
							prepare_skill("cuff", "meinu-quanfa");
							u_pfm = u_pfm + ({(: perform_action, "cuff.shexin" :)});		//��Ůȭ��pfm:����
							set("f_skill","meinu-quanfa");
						break;

					}
					switch(random(2))
					{
						case 0:
							set_skill("yunu-jianfa",500);                               //��Ĺ�ͼ���������Ů���Ľ�
							map_skill("sword","yunu-jianfa");
							w_parry="yunu-jianfa";
							u_pfm=u_pfm + ({(: perform_action, "sword.suxin" :)});      //��Ů���Ľ�pfm������
							u_weapon="sword";
							set("f_w_skill","yunu-jianfa");
						break;
						case 1:
							set_skill("quanzhen-jianfa",500);                               //��Ĺ�ͼ�������ȫ�潣��
							map_skill("sword","quanzhen-jianfa");
							w_parry="quanzhen-jianfa";
							u_pfm=u_pfm + ({(: perform_action, "sword.qixing" :)});     	//ȫ�潣��pfm�����Ǿ۶�
							u_pfm=u_pfm + ({(: perform_action, "sword.sanqing" :)});   	    //�����
							u_weapon="sword";
							set("f_w_skill","quanzhen-jianfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("anran-zhang",500);								//��Ĺ�߼����֣���Ȼ������		
							map_skill("strike","anran-zhang");
							nw_parry="anran-zhang";
							prepare_skill("strike","anran-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.anran" :)});     //��Ȼ������pfm����Ȼ
							u_pfm = u_pfm + ({(: perform_action, "strike.jishi" :)});     //��Ȼ������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.xiaohun" :)});     //��Ȼ������pfm������
							set("f_skill","anran-zhang");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("xuantie-jianfa",500);									//��Ĺ�߼���������������
							map_skill("sword","xuantie-jianfa");
							w_parry="xuantie-jianfa";
							set("env/��������",random(2)?"����":"��ӿ");						//pfm ����������趨
							u_pfm = u_pfm + ({(: perform_action, "sword.haichao" :)});        	//����pfm������
							u_pfm = u_pfm + ({(: perform_action, "sword.wujian" :)});			//�޽�
							u_weapon="sword";
							set("f_w_skill","xuantie-jianfa");
						break;
						case 1:
							set_skill("yinsuo-jinling",500);									//��Ĺ�߼���������������
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}							
								set_skill("meinu-quanfa",500);										//pfm sanwu������֮һ
								map_skill("cuff","meinu-quanfa");
								prepare_skill("cuff", "meinu-quanfa");
								set("f_skill","meinu-quanfa");
							}
							map_skill("whip","yinsuo-jinling");
							set("gmsanwu",1);
							w_parry="yinsuo-jinling";
							u_pfm = u_pfm + ({(: perform_action, "whip.sanwu" :)});        	//��������pfm������������
//							u_pfm = u_pfm + ({(: perform_action, "whip.yueyin" :)});			//yueyin
							u_weapon="whip";
							set("f_w_skill","yinsuo-jinling");
						break;
					}					
				break;	
				}
			break;//end case gm	

		case "mr":												//�趨Ľ���书
			set("family/family_name","����Ľ��");
			set_skill("shenyuan-gong",500);					//Ľ���ڹ�����Ԫ��			
			set_skill("yanling-shenfa",500);						//Ľ���Ṧ��������
			set_skill("douzhuan-xingyi",500);						//��ת����
			map_skill("force", "shenyuan-gong");
			map_skill("dodge", "yanling-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "shenyuan" :)});   		//��Ԫ��pfm����Ԫ
			u_pfm=u_pfm + ({(: perform_action, "parry.xingyi" :)});     //��ת����pfm������

			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("xingyi-zhang",500);                             //Ľ�ݵͼ����֣�������
							map_skill("strike","xingyi-zhang");
							nw_parry="xingyi-zhang";
							prepare_skill("strike", "xingyi-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.riyue" :)});        //������pfm������ͬ��
							set("f_skill","xingyi-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("murong-daofa",500);                               //Ľ�ݵͼ�������Ľ�ݵ���
							map_skill("blade","murong-daofa");
							w_parry="murong-daofa";
							u_pfm=u_pfm + ({(: perform_action, "blade.daoying" :)});     //Ľ�ݵ���pfm����Ӱ��
							u_weapon="blade";
							set("f_w_skill","murong-daofa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("canhe-zhi",500);								//Ľ�ݸ߼����֣��κ�ָ
							map_skill("finger","canhe-zhi");
							nw_parry="douzhuan-xingyi";                             //ֻ���ڲκ�ָ������£������趨douzhuan-xingyiΪparry���ҷ�pfm 
							prepare_skill("finger","canhe-zhi");
							u_pfm = u_pfm + ({(: perform_action, "finger.ci" :)});     //�κ�ָpfm����
							set("f_skill","canhe-zhi");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("murong-jianfa",500);										//Ľ�ݸ߼�������Ľ�ݽ���
							map_skill("sword","murong-jianfa");
							w_parry="murong-jianfa";
							u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});        	//Ľ�ݽ���pfm������
							u_pfm = u_pfm + ({(: perform_action, "sword.sanhua" :)});			//ɢ��
							u_weapon="sword";
							set("f_w_skill","murong-jianfa");
						break;
					}					
				break;	
				}
			break;//end case mr				
			
		case "sld":												//�趨�������书
			set("family/family_name","������");
			set("family/master_id","hong antong");
			set_skill("dulong-dafa",500);						//�������ڹ��������� 			
			set_skill("youlong-shenfa",500);					//�������Ṧ��������
			set_skill("shenlong-yaoli",200);					//�������������ҩ��ѧ
			map_skill("force", "dulong-dafa");
			map_skill("dodge", "youlong-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "wudi" :)});   		//������pfm���޵�
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("hansha-sheying",500);                             //�������ͼ����֣���ɳ��Ӱ
							map_skill("throwing","hansha-sheying");
							nw_parry="hansha-sheying";
							prepare_skill("throwing", "hansha-sheying");
							set("f_skill","hansha-sheying");
						break;
						case 1:
							set_skill("shenlong-tuifa",500);                             //�������ͼ����֣������ȷ�
							map_skill("leg","shenlong-tuifa");
							nw_parry="shenlong-tuifa";
							prepare_skill("leg", "shenlong-tuifa");
							set("env/zhuiming",random(60)+1);
							u_pfm=u_pfm + ({(: perform_action, "leg.zhuiming" :)});          //�����ȷ�pfm��׷��
							set("f_skill","shenlong-tuifa");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("lingshe-bianfa",500);                               //�������ͼ����������߱޷�
							map_skill("whip","lingshe-bianfa");
							w_parry="lingshe-bianfa";
							u_pfm=u_pfm + ({(: perform_action, "whip.chan" :)});          //���߱޷�pfm������
							u_pfm=u_pfm + ({(: perform_action, "whip.sandou" :)});        //���߱޷�pfm������
							u_weapon="whip";
							set("f_w_skill","lingshe-bianfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("huagu-mianzhang",500);								//�������߼����֣���������
							map_skill("strike","huagu-mianzhang");
							nw_parry="huagu-mianzhang";
							prepare_skill("strike","huagu-mianzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.bujue" :)});     //��������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.huagu" :)});     //��������pfm������
//							u_pfm = u_pfm + ({(: perform_action, "strike.puhuo" :)});     //��������pfm���ɶ��˻�
							set("f_skill","huagu-mianzhang");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tenglong-bifa",500);										//�������߼�����������ذ��
							map_skill("dagger","tenglong-bifa");
							w_parry="tenglong-bifa";
							u_pfm = u_pfm + ({(: perform_action, "dagger.diqing" :)});        	//����ذ��pfm�����ཱུ��
							u_pfm = u_pfm + ({(: perform_action, "dagger.feiyan" :)});			//�������
							u_pfm = u_pfm + ({(: perform_action, "dagger.guifei" :)});			//��������	
							u_pfm = u_pfm + ({(: perform_action, "dagger.luda" :)});			//³�����
							u_pfm = u_pfm + ({(: perform_action, "dagger.xiaolian" :)});		//С�����
							u_pfm = u_pfm + ({(: perform_action, "dagger.zixu" :)});			//����ٶ�
							u_weapon="dagger";
							set("f_w_skill","tenglong-bifa");
						break;
					}					
				break;	
				}
			break;//end case sld		

		case "xx":												//�趨�����书
			set("family/family_name","������");
			set_skill("huagong-dafa",500);						//�����ڹ���������			
			set_skill("zhaixingshu",500);						//�����Ṧ��ժ���� 
			map_skill("force", "huagong-dafa");
			map_skill("dodge", "zhaixingshu");
//			u_pfm=u_pfm + ({(: exert_function, "duwu" :)});   //������pfm������
			set_skill("poison",200);						  // judu need poison >150							
			u_pfm=u_pfm + ({(: exert_function, "judu" :)});   //�۶�
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("sanyin-zhua",500);                             //���޵ͼ����֣��������צ
							map_skill("claw","sanyin-zhua");
							nw_parry="sanyin-zhua";
							prepare_skill("claw", "sanyin-zhua");
							set("f_skill","sanyin-zhua");
							break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianshan-zhang",500);										//���޸߼���������ɽ�ȷ�
							map_skill("staff","tianshan-zhang");
							w_parry="tianshan-zhang";
							u_pfm = u_pfm + ({(: perform_action, "staff.feizhi" :)});        	//��ɽ�ȷ�pfm������
							u_weapon="staff";
							set("f_w_skill","tianshan-zhang");
						break;
					}	
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("chousui-zhang",500);								//���޸߼����֣�������		
							map_skill("strike","chousui-zhang");
							nw_parry="chousui-zhang";
							prepare_skill("strike","chousui-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.biyan" :)});     //������pfm������
//							u_pfm = u_pfm + ({(: perform_action, "strike.fushidu" :)});     //������pfm����ʬ��
							u_pfm = u_pfm + ({(: perform_action, "strike.huoqiang" :)});     //������pfm����ǽ
							u_pfm = u_pfm + ({(: perform_action, "strike.huoqiu" :)});     //������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.yinhuo" :)});     //������pfm������
							set("f_skill","chousui-zhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianshan-zhang",500);										//���޸߼���������ɽ�ȷ�
							map_skill("staff","tianshan-zhang");
							w_parry="tianshan-zhang";
							u_pfm = u_pfm + ({(: perform_action, "staff.feizhi" :)});        	//��ɽ�ȷ�pfm������
							u_weapon="staff";
							set("f_w_skill","tianshan-zhang");
						break;
					}					
				break;	
				}
			break;//end case xx
			
		case "em":												//�趨��ü�书
			set("family/family_name","��ü��");
			set_skill("linji-zhuang",500);						//��ü�ڹ����ټ�ʮ��ׯ			
			set_skill("anying-fuxiang",500);					//��ü�Ṧ����Ӱ����
			set_skill("dacheng-fofa",500);						//��ü�����˷�
			set("class","bonze");
			map_skill("force", "linji-zhuang");
			map_skill("dodge", "anying-fuxiang");
			u_pfm=u_pfm + ({(: exert_function, "fengyun" :)});   //�ټ�ʮ��ׯpfm������
			u_pfm=u_pfm + ({(: exert_function, "riyue" :)});	 //����
			u_pfm=u_pfm + ({(: exert_function, "tiandi" :)});    //��� 
			u_pfm=u_pfm + ({(: exert_function, "wuwo" :)});      //����
			u_pfm=u_pfm + ({(: exert_function, "yinyang" :)});   //����  
			if(random(5)==1)
			u_pfm=u_pfm + ({(: exert_function, "youming" :)});   //��ڤ  
			u_pfm=u_pfm + ({(: exert_function, "zhixin" :)});    //֮�� 
     
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("sixiang-zhang",500);                             //��ü�ͼ����֣�������
							map_skill("strike","sixiang-zhang");
							nw_parry="sixiang-zhang";
							prepare_skill("strike", "sixiang-zhang");
							set("f_skill","sixiang-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("yanxing-daofa",500);                               //��ü�ͼ����������е���
							map_skill("blade","yanxing-daofa");
							w_parry="yanxing-daofa";
							u_pfm=u_pfm + ({(: perform_action, "blade.feiyang" :)});          //���е���pfm������
							u_pfm=u_pfm + ({(: perform_action, "blade.huanying" :)});         //���е���pfm����Ӱ
							u_weapon="blade";
							set("f_w_skill","yanxing-daofa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("jieshou-jiushi",500);								//��ü�߼����֣����־�ʽ		
							map_skill("hand","jieshou-jiushi");
							nw_parry="jieshou-jiushi";
							prepare_skill("hand","jieshou-jiushi");
							u_pfm = u_pfm + ({(: perform_action, "hand.foguang" :)});     //���־�ʽpfm������
							set("f_skill","jieshou-jiushi");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("huifeng-jian",500);										//��ü�߼��������ط������
							map_skill("sword","huifeng-jian");
							w_parry="huifeng-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        		//�ط������pfm����
							u_pfm = u_pfm + ({(: perform_action, "sword.liaoyuan" :)});			//��ԭ
							u_pfm = u_pfm + ({(: perform_action, "sword.mie" :)});				//��
							u_weapon="sword";
							set("f_w_skill","huifeng-jian");
						break;
					}					
				break;	
				}
			break;//end case em		
		case "mj":												//�趨�����书
			set("family/family_name","����");
			set_skill("piaoyi-shenfa",500);						//�����Ṧ��Ʈ����
			map_skill("dodge", "piaoyi-shenfa");
			set_skill("qiankun-danuoyi",500);
			u_pfm=u_pfm + ({(: perform_action, "parry.hua" :)});	
			u_pfm=u_pfm + ({(: perform_action, "parry.xu" :)});	
			u_pfm=u_pfm + ({(: perform_action, "parry.yin" :)});
			switch(in_level)
			{
				case 0:
					set_skill("shenghuo-shengong",500);									//���̵ͼ��ڹ���ʥ����
					map_skill("force","shenghuo-shengong");
					u_pfm=u_pfm + ({(: exert_function, "tougu" :)});	 //ʥ����pfm:͸��
					u_pfm=u_pfm + ({(: exert_function, "yinfeng" :)});	 //����		
	

					switch(random(2))
					{
						case 0:
							set_skill("yingzhua-shou",500);                             //���̵ͼ����֣�ӥצ������
							map_skill("hand","yingzhua-shou");
							nw_parry="qiankun-danuoyi";									//�趨Ǭ����Ų��Ϊ�м�
							prepare_skill("hand", "yingzhua-shou");
							set("f_skill","yingzhua-shou");
						break;
						case 1:
							set_skill("hanbing-mianzhang",500);                             //���̵ͼ����֣���������
							map_skill("strike","hanbing-mianzhang");
							nw_parry="hanbing-mianzhang";									//pfm xixue Ҫ��parry Ϊhanbing-mianzhang
							prepare_skill("strike", "hanbing-mianzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.xixue" :)});		//��������pfm:��Ѫ
							set("f_skill","hanbing-mianzhang");
						break;

					}
					switch(random(2))
					{
						case 0:
							set_skill("liehuo-jian",500);                             		  //���̵ͼ��������һ�
							map_skill("sword","liehuo-jian");
							w_parry="qiankun-danuoyi";									      //�趨Ǭ����Ų��Ϊ�м�
							u_weapon="sword";
							set("f_w_skill","liehuo-jian");
						break;
						case 1:
							set_skill("lieyan-dao",500);                              		 //���̵ͼ����������浶
							map_skill("blade","lieyan-dao");
							w_parry="qiankun-danuoyi";										 //�趨Ǭ����Ų��Ϊ�м�
							u_pfm = u_pfm + ({(: perform_action, "blade.shenghuo" :)});		 //���浶pfm:ʥ��
							u_weapon="blade";
							set("f_w_skill","lieyan-dao");
						break;
					}
				break;
				case 1:
					set_skill("jiuyang-shengong",500);									//���̸߼��ڹ���������
					set_skill("shenghuo-shengong",500);									//���̵ͼ��ڹ���ʥ����
					map_skill("force","jiuyang-shengong");
					u_pfm=u_pfm + ({(: exert_function, "tougu" :)});	 //ʥ����pfm:͸��
					u_pfm=u_pfm + ({(: exert_function, "yinfeng" :)});	 //����	
					u_pfm=u_pfm + ({(: exert_function, "powerup" :)});	 //powerup	
					if(!in_weapon)
					switch(random(1))													//����ʥ�������Ϊcuff����ǿ��Ҫ��tisha��Ҫcuff Ϊshenghuo-lingfa �򲻺�
					{																	//���������˿��ֺ����̵������书����ȭ�� campsun ע	
						case 0:
							set_skill("qishang-quan",500);								//���̸߼����֣�����ȭ		
							map_skill("cuff","qishang-quan");
							nw_parry="qiankun-danuoyi";										//�趨Ǭ����Ų��Ϊ�м�
							prepare_skill("cuff","qishang-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.qishang" :)});     //����ȭpfm������
							u_pfm = u_pfm + ({(: perform_action, "cuff.duanhun" :)});     //����ȭpfm���ϻ�
							set("f_skill","qishang-quan");
						break;
					}
					else
					switch(random(1))
					{
						case 0:
							set_skill("shenghuo-lingfa",500);										//���̸߼�������ʥ���
							map_skill("dagger","shenghuo-lingfa");									//�趨Ǭ����Ų��Ϊ�м�
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}																		//��ֹhubei
								
								map_skill("cuff","shenghuo-lingfa");
								prepare_skill("cuff","shenghuo-lingfa");
								nw_parry="qiankun-danuoyi";
								set("f_skill","shenghuo-lingfa");
							}
							w_parry="qiankun-danuoyi";
							u_pfm = u_pfm + ({(: perform_action, "dagger.duo" :)});        	//ʥ���pfm����
							u_pfm = u_pfm + ({(: perform_action, "dagger.ji" :)});			//��
							u_pfm = u_pfm + ({(: perform_action, "dagger.tisha" :)});			//��ɳ	
							u_pfm = u_pfm + ({(: perform_action, "dagger.xinmo" :)});			//��ħ
							u_weapon="dagger";
							set("f_w_skill","shenghuo-lingfa");
						break;
					}					
				break;	
				}
			break;//end case mj	

		case "thd":												//�趨�һ����书
			set("family/family_name","�һ���");
			set_skill("bihai-chaosheng",500);					//�һ����ڹ����̺�������			
			set_skill("suibo-zhuliu",500);						//�һ����Ṧ���沨���� 
			set_skill("qimen-bagua",200);
			set("thd/perform",31);
			map_skill("force", "bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
//			u_pfm=u_pfm + ({(: exert_function, "play" :)});   //�̺�������pfm������
			u_pfm=u_pfm + ({(: exert_function, "maze" :)});     //����
			u_pfm=u_pfm + ({(: exert_function, "qimen" :)});     //��������
			u_pfm=u_pfm + ({(: perform_action, "dodge.wuzhuan" :)});			//�沨����pfm:��ת

			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("lanhua-shou",500);                             //�һ����ͼ����֣�������Ѩ��
							map_skill("hand","lanhua-shou");
							nw_parry="lanhua-shou";
							prepare_skill("hand", "lanhua-shou");
							u_pfm=u_pfm + ({(: perform_action, "hand.fuxue" :)});        //������Ѩ��pfm����Ѩ
							set("f_skill","lanhua-shou");
						break;
						case 1:
							set_skill("luoying-zhang",500);                             //�һ����ͼ����֣���Ӣ����
							map_skill("strike","luoying-zhang");
							nw_parry="luoying-zhang";
							prepare_skill("strike", "luoying-zhang");
//							u_pfm=u_pfm + ({(: perform_action, "strike.fugu" :)});        //��Ӣ����pfm������
							u_pfm=u_pfm + ({(: perform_action, "strike.pikong" :)});        //��Ӣ����pfm������
//							u_pfm=u_pfm + ({(: perform_action, "strike.bading" :)});        //��Ӣ����pfm���ζ�
							set("f_skill","luoying-zhang");

						break;
						case 2:
							set_skill("xuanfeng-tui",500);                             //�һ����ͼ����֣�����ɨҶ��
							set_skill("luoying-zhang",500);                             //pfm xuanfeng ��Ҫ��
							map_skill("strike","luoying-zhang");
							map_skill("leg","xuanfeng-tui");
							nw_parry="xuanfeng-tui";
							prepare_skill("leg", "xuanfeng-tui");
							u_pfm=u_pfm + ({(: perform_action, "leg.kuangfeng" :)});        //����ɨҶ��pfm�����
							set("f_skill","xuanfeng-tui");
						break;
					}
					switch(random(1))															//thd �޵ͼ�����,�����趨�ͼ�����Ϊyxj
					{
						case 0:
							set_skill("yuxiao-jian",500);										//�һ����߼����������｣��
							set_skill("tanzhi-shentong",500);
							map_skill("finger","tanzhi-shentong");
							set_skill("xuanfeng-tui",500);
							map_skill("leg","xuanfeng-tui");
							set_skill("luoying-zhang",500);
							map_skill("strike","luoying-zhang");
							set_skill("lanhua-shou",500); 
							map_skill("hand","lanhua-shou");
							map_skill("sword","yuxiao-jian");
							w_parry="yuxiao-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//���｣��pfm����Ӱ
							u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//����
							u_weapon="xiao";													//pfm feiying ��Ҫװ����Ϊ����		
							set("f_w_skill","yuxiao-jian");
						break;
					}
																						
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("tanzhi-shentong",500);								//�һ����߼����֣���ָ��ͨ	
							map_skill("finger","tanzhi-shentong");
							map_skill("throwing","tanzhi-shentong");						//��ָ��ͨ������
							nw_parry="tanzhi-shentong";
							prepare_skill("finger","tanzhi-shentong");
							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)});     //��ָ��ͨpfm��Ǭ��һָ
							u_pfm = u_pfm + ({(: perform_action, "finger.shentong" :)});     //��ָ��ͨpfm����ͨ
//							u_pfm = u_pfm + ({(: perform_action, "finger.huayu" :)});     //��ָ��ͨpfm�����컨��
							set("f_skill","tanzhi-shentong");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("yuxiao-jian",500);										//�һ����߼����������｣��
							set_skill("tanzhi-shentong",500);
							map_skill("finger","tanzhi-shentong");
							set_skill("xuanfeng-tui",500);
							map_skill("leg","xuanfeng-tui");
							set_skill("luoying-zhang",500);
							map_skill("strike","luoying-zhang");
							set_skill("lanhua-shou",500); 
							map_skill("hand","lanhua-shou");
							map_skill("sword","yuxiao-jian");
							w_parry="yuxiao-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//���｣��pfm����Ӱ
							u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//����
							u_weapon="xiao";													//pfm feiying ��Ҫװ����Ϊ����		
							set("f_w_skill","yuxiao-jian");
						break;
					}					
				break;	
				}
			break;//end case thd
			
		case "tls":																		//tls kungfu set							
			set("family/family_name","������");
			set_skill("qiantian-yiyang",500);											//�����µͼ��ڹ���Ǭ��һ��
			set_skill("tianlong-xiang",500);											//�������Ṧ��������
			set_skill("buddhism",200);
			set("class","bonze");		
			map_skill("force", "qiantian-yiyang");
			map_skill("dodge", "tianlong-xiang");
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});   
			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("qingyan-zhang",500);                             		//�����µͼ����֣�����������
							map_skill("strike","qingyan-zhang");
							nw_parry="qingyan-zhang";
							prepare_skill("strike", "qingyan-zhang");
							set("f_skill","qingyan-zhang");
						break;
						case 1:
							set_skill("duanjia-quan",500);                             			//�����µͼ����֣��μ�ȭ��
							map_skill("cuff","duanjia-quan");
							nw_parry="duanjia-quan";
							prepare_skill("cuff", "duanjia-quan");
							set("f_skill","duanjia-quan");
						break;
						case 2:
							set_skill("yiyang-zhi",500);										//�����µͼ����֣�һ��ָ
							map_skill("finger","yiyang-zhi");
							nw_parry="yiyang-zhi";
							prepare_skill("finger","yiyang-zhi");
							u_pfm = u_pfm + ({(: perform_action, "finger.sandie" :)}); 			//һ��ָpfm����������
							u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)}); 	//һָ����
//							u_pfm = u_pfm + ({(: perform_action, "qianlong" :)});     
							set("f_skill","yiyang-zhi");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("duanjia-jianfa",500);                               		//�����µͼ��������μҽ���
							map_skill("sword","duanjia-jianfa");
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}
								set_skill("qingyan-zhang",500);                             
								map_skill("strike","qingyan-zhang");
								prepare_skill("strike", "qingyan-zhang");
								set("f_skill","qingyan-zhang");
							}
							w_parry="qingyan-zhang";
							u_pfm=u_pfm + ({(: perform_action, "sword.fenglei" :)});          	//�μҽ���pfm�������Ļ�
							u_weapon="sword";
							set("f_w_skill","duanjia-jianfa");						
						break;
					}
				break;
				case 1:
					set_skill("kurong-changong",500);											//�����¸߼��ڹ�����������
					map_skill("force","kurong-changong");
					switch(random(2))
					{
						case 0:										
							map_skill("strike","kurong-changong");								//�����¸߼����֣���������
							nw_parry="kurong-changong";
							prepare_skill("strike","kurong-changong");
							u_pfm = u_pfm + ({(: exert_function, "rong" :)}); 					//��������pfm����
							u_pfm = u_pfm + ({(: perform_action, "strike.jiuchong" :)});		//������
							set("f_skill","kurong-changong");     
						break;
						case 1:
							u_liumai=str_liumai[random(sizeof(str_liumai))];					//�����¸߼����֣�������
							set("env/liumai",u_liumai);
							set("liumai-shenjian/"+u_liumai,1);
							set_skill("yiyang-zhi",500);
							set_skill("liumai-shenjian",500);										
							map_skill("finger","yiyang-zhi");
							nw_parry="yiyang-zhi";
							prepare_skill("finger","yiyang-zhi");
							u_pfm = u_pfm + ({(: perform_action, "finger.sandie" :)}); 
							u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)}); 
//							u_pfm = u_pfm + ({(: perform_action, "qianlong" :)});     
							set("f_skill","liumai-shenjian");
						break;
						
					}
					switch(random(2))
					{
						case 0:
							set_skill("cihang-bian",500);										//�����¸߼��������Ⱥ���
							set("shen",5000000);												//need for pfm	
							map_skill("whip","cihang-bian");
							w_parry="cihang-bian";
							u_pfm = u_pfm + ({(: perform_action, "whip.cibei" :)});        		//�Ⱥ���pfm���ȱ��־�
							u_weapon="whip";
							set("f_w_skill","cihang-bian");
						break;
						case 1:
							set_skill("pangen-fu",500);											//�����¸߼��������̸���ḫ
							map_skill("axe","pangen-fu");
							w_parry="pangen-fu";
							u_pfm = u_pfm + ({(: perform_action, "axe.jingtian" :)});        	//�̸���ḫpfm��������Ƹ�
							u_weapon="axe";
							set("f_w_skill","pangen-fu");
						break;
					}					
				break;	
				}
			break;//end case tls		

		case "sl":		
			set("family/family_name","������");
			set_skill("yijin-jing",500);													//�����ڹ����׽
			set_skill("shaolin-shenfa",500);												//�����Ṧ��������
			set_skill("buddhism",200);														//������������ķ�
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "jingang" :)});   							//�׽pfm����ղ�������
			switch(in_level)
			{
				case 0:
					switch(random(8))
					{
						case 0:
							set_skill("fengyun-shou",500);                             		//���ֵͼ����֣�������
							map_skill("hand","fengyun-shou");
							nw_parry="fengyun-shou";
							prepare_skill("hand", "fengyun-shou");
							set("f_skill","fengyun-shou");
						break;
						case 1:
							set_skill("yingzhua-gong",500);                             	//���ֵͼ����֣�ӥצ��
							map_skill("claw","yingzhua-gong");
							nw_parry="yingzhua-gong";
							prepare_skill("claw", "yingzhua-gong");
							set("f_skill","yingzhua-gong");
						break;
						case 2:
							set_skill("mohe-zhi",500);                             			//���ֵͼ����֣�Ħڭָ
							map_skill("finger","mohe-zhi");
							nw_parry="mohe-zhi";
							prepare_skill("finger", "mohe-zhi");
							set("f_skill","mohe-zhi");
						break;
						case 3:
							set_skill("jimie-zhua",500);                             		//���ֵͼ����֣�����צ
							map_skill("claw","jimie-zhua");
							nw_parry="jimie-zhua";
							prepare_skill("claw", "jimie-zhua");
							set("f_skill","jimie-zhua");
						break;
						case 4:
							set_skill("shaolin-tantui",500);                             	//���ֵͼ����֣����ֵ���
							map_skill("leg","shaolin-tantui");
							nw_parry="shaolin-tantui";
							prepare_skill("leg", "shaolin-tantui");
							set("f_skill","shaolin-tantui");
						break;
						case 5:
							set_skill("weituo-zhang",500);                             		//���ֵͼ����֣�Τ����
							map_skill("strike","weituo-zhang");
							nw_parry="weituo-zhang";
							prepare_skill("strike", "weituo-zhang");
							set("f_skill","weituo-zhang");
						break;
						case 6:
							set_skill("luohan-quan",500);                             		//���ֵͼ����֣��޺�ȭ
							map_skill("cuff","luohan-quan");
							nw_parry="luohan-quan";
							prepare_skill("cuff", "luohan-quan");
							set("f_skill","luohan-quan");
						break;
						case 7:
							set_skill("sanhua-zhang",500);     								//���ֵͼ����֣�ɢ����
							set_skill("nianhua-zhi",500);                             		//���ֵͼ����֣��黨ָ
                      		map_skill("strike","sanhua-zhang");
    						map_skill("finger","nianhua-zhi");
							prepare_skill("strike", "sanhua-zhang");
							prepare_skill("finger", "nianhua-zhi");
							nw_parry="nianhua-zhi";
							u_pfm = u_pfm + ({(: perform_action, "strike.sanhua" :)});
							u_pfm = u_pfm + ({(: perform_action, "finger.fuxue" :)});    
							set("f_skill","sanhua-zhang");									//ɢ����pfm���ļ�ɢ��
							set("f_skill2","nianhua-zhi");									//�黨ָpfm���黨��Ѩ
							
						break;

					}
					switch(random(8))
					{
						case 0:
							set_skill("xiuluo-dao",500);                               		//���ֵͼ����������޵� 
							map_skill("blade","xiuluo-dao");
							w_parry="xiuluo-dao";
							u_weapon="blade";
							set("f_w_skill","xiuluo-dao");
						break;
						case 1:
							set_skill("pudu-zhang",500);                               		//���ֵͼ��������ն���
							map_skill("staff","pudu-zhang");
							w_parry="pudu-zhang";
							u_weapon="staff";
							set("f_w_skill","pudu-zhang");
						break;
						case 2:
							set_skill("zui-gun",500);                               		//���ֵͼ��������������
							map_skill("club","zui-gun");
							apply_condition("drunk",300);
							w_parry="zui-gun";
							u_weapon="club";
							u_pfm = u_pfm + ({(: perform_action, "club.zuijiu" :)}); 		//�������pfm���������
							set("f_w_skill","zui-gun");   
						break;
						case 3:
							set_skill("damo-jian",500);                               		//���ֵͼ���������Ħ��
							map_skill("sword","damo-jian");
							w_parry="damo-jian";
							u_weapon="sword";
							set("f_w_skill","damo-jian");
						break;
						case 4:
							set_skill("weituo-gun",500);                               		//���ֵͼ�������Τ�ӹ�
							map_skill("club","weituo-gun");
							w_parry="weituo-gun";
							u_weapon="club";
							set("f_w_skill","weituo-gun");
						break;
						case 5:
							set_skill("cibei-dao",500);                               		//���ֵͼ��������ȱ���
							map_skill("blade","cibei-dao");
							w_parry="cibei-dao";
							u_weapon="blade";
							set("f_w_skill","cibei-dao");
						break;
						case 6:
							set_skill("fumo-jian",500);                               		//���ֵͼ���������ħ��	
							map_skill("sword","fumo-jian");
							w_parry="fumo-jian";
							u_weapon="sword";
							set("f_w_skill","fumo-jian");
						break;
						case 7:
							set_skill("wuchang-zhang",500);                               	//���ֵͼ��������޳���
							map_skill("staff","wuchang-zhang");
							w_parry="wuchang-zhang";
							u_weapon="staff";
							set("f_w_skill","wuchang-zhang");
						break;
					}
				break;
				case 1:
					switch(random(4))
					{
						case 0:
							set_skill("yizhi-chan",500);										//���ָ߼����֣�һָ��
							set_skill("longzhua-gong",500);										//���ָ߼����֣���צ��
							map_skill("claw","longzhua-gong");
							map_skill("finger","yizhi-chan");
							prepare_skill("claw","longzhua-gong");
							prepare_skill("finger","yizhi-chan");
							nw_parry="yizhi-chan";
							u_pfm = u_pfm + ({(: perform_action, "finger.wofo" :)});    		//һָ��pfm������ҷ�
							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//һָǬ��
							u_pfm = u_pfm + ({(: perform_action, "claw.canyun" :)}); 			//��צ��pfm��������
							set("f_skill","yizhi-chan");
							set("f_skill2","longzhua-gong");   
   						break;
						case 1:
							set_skill("ruying-suixingtui",500);									//���ָ߼����֣���Ӱ������
							set_skill("qianye-shou",500);										//���ָ߼����֣�����ǧҶ��
							map_skill("leg","ruying-suixingtui");
							map_skill("hand","qianye-shou");
							prepare_skill("leg","ruying-suixingtui");
							prepare_skill("hand","qianye-shou");
							nw_parry="qianye-shou";
							u_pfm = u_pfm + ({(: perform_action, "hand.qianshou" :)});    		//����ǧҶ��pfm��ǧ������
							u_pfm = u_pfm + ({(: perform_action, "leg.ruying" :)});    			//��Ӱ������pfm����Ӱ����
							set("f_skill","ruying-suixingtui");
							set("f_skill2","qianye-shou");
						break;
						case 2:
							set_skill("jingang-quan",500);										//���ָ߼����֣�����ȭ
							map_skill("cuff","jingang-quan");
							set_skill("banruo-zhang",500);										//���ָ߼����֣�������
							map_skill("strike","banruo-zhang");
							nw_parry="banruo-zhang";
							prepare_skill("strike","banruo-zhang");
							prepare_skill("cuff","jingang-quan");
							u_pfm = u_pfm + ({(: perform_action, "strike.chaodu" :)}); 			//������pfm������������
							if(random(5)==1)
							u_pfm = u_pfm + ({(: perform_action, "strike.yipai" :)});   		//һ����ɢ
							u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});    			//����ȭpfm����շ�ħ
							set("f_skill","jingang-quan");
							set("f_skill2","banruo-zhang");
 						break;
 						case 3:
							set_skill("wuxiang-zhi",500);										//���ָ߼����֣������ָ
							map_skill("finger","wuxiang-zhi");
							prepare_skill("finger","wuxiang-zhi");
							nw_parry="wuxiang-zhi";
 							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//�����ָpfm������Ǭ��
							set("f_skill","wuxiang-zhi");
   						break;
					}
					switch(random(3))
					{
						case 0:
							set_skill("riyue-bian",500);										//���ָ߼����������±޷�
							map_skill("whip","riyue-bian");
							w_parry="riyue-bian";
							u_pfm = u_pfm + ({(: perform_action, "whip.fumoquan" :)});        	//���±޷�pfm����շ�ħȦ
							u_pfm = u_pfm + ({(: perform_action, "whip.chanrao" :)});        	//������� 
							u_weapon="whip";
							set("f_w_skill","riyue-bian");
						break;
						case 1:
							set_skill("ranmu-daofa",500);										//���ָ߼�������ȼľ����
							map_skill("blade","ranmu-daofa");
							w_parry="ranmu-daofa";
							u_pfm = u_pfm + ({(: perform_action, "blade.fentian" :)});			//ȼľ����pfm���ٻ����
							u_pfm = u_pfm + ({(: perform_action, "blade.fenwo" :)});        	//����
//							u_pfm = u_pfm + ({(: perform_action, "blade.fenxin" :)});        	//���� ��Ҫľ�����ܷ�
							u_weapon="blade";
							set("f_w_skill","ranmu-daofa");
						break;
						case 2:
							set_skill("weituo-chu",500);										//���ָ߼�������Τ����
							map_skill("club","weituo-chu");
							w_parry="weituo-chu";
							u_pfm = u_pfm + ({(: perform_action, "club.leidong" :)});			//Τ����pfm���׶�����
							u_pfm = u_pfm + ({(: perform_action, "club.chaodu" :)});        	//���ȼ��� 
							u_weapon="club";
							set("f_w_skill","weituo-chu");
						break;
					}					
				break;	
				}
			break;//end case sl	
		case "kl":
			set("family/family_name","������");
			set_skill("xuantian-wuji",500);													//�����ڹ��������޼���
			set_skill("taxue-wuhen",500);													//�����Ṧ��̤ѩ�޺�
			set_skill("art",200);															//������������黭	
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   							//�����޼���pfm������
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     							//�ۺ�
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("chuanyun-tui",500);                            		//���صͼ����֣�������
							map_skill("leg","chuanyun-tui");
							nw_parry="chuanyun-tui";
							prepare_skill("leg", "chuanyun-tui");
							set("f_skill","chuanyun-tui");
						break;
						case 1:
							set_skill("zhentian-quan",500);                            		//���صͼ����֣�����ȭ
							map_skill("cuff","zhentian-quan");
							nw_parry="zhentian-quan";
							prepare_skill("cuff", "zhentian-quan");
							set("f_skill","zhentian-quan");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("xunlei-jian",500);                              		//���صͼ�������Ѹ�׽�
							map_skill("sword","xunlei-jian");
							w_parry="xunlei-jian";
							u_weapon="sword";
							set("f_w_skill","xunlei-jian");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("kunlun-zhang",500);									 //���ظ߼����֣������Ʒ�
							map_skill("strike","kunlun-zhang");
							nw_parry="kunlun-zhang";
							prepare_skill("strike","kunlun-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.diezhang" :)});     //�����Ʒ�pfm����ɽ����
							set("f_skill","kunlun-zhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("liangyi-jian",500);									//���ظ߼����������ǽ���	
							map_skill("sword","liangyi-jian");
							w_parry="liangyi-jian";
//							u_pfm = u_pfm + ({(: perform_action, "sword.hebi" :)});        	//���ǽ���pfm��˫���ϱ� 
							u_weapon="sword";
							set("f_w_skill","liangyi-jian");
						break;
					}					
				break;	
				}
			break;//end case kl	
		case "9y":
			set("family/family_name","�����澭����");
			set_skill("jiuyin-zhengong",500);												//�����ڹ��������湦	
			set_skill("jiuyin-shenfa",500);													//�����Ṧ��������	
			set_skill("daode-jing",200);			
			map_skill("force", "jiuyin-zhengong");
			map_skill("dodge", "jiuyin-shenfa");
			u_pfm=u_pfm + ({(: exert_function, "yihuen" :)});   
			u_pfm=u_pfm + ({(: exert_function, "zongjue" :)});   							//�����ܾ�
			u_pfm=u_pfm + ({(: perform_action, "dodge.huanyinbu" :)});      				//������pfm��������
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("jiuyin-baiguzhua",500);                              //�����ͼ����֣������׹�צ
							map_skill("claw","jiuyin-baiguzhua");
							nw_parry="jiuyin-baiguzhua";
							prepare_skill("claw", "jiuyin-baiguzhua");
							u_pfm=u_pfm + ({(: perform_action, "claw.jiuyin" :)});			//�����׹�צpfm����������צ
							set("f_skill","jiuyin-baiguzhua");       
						break;
						case 1:
							set_skill("cuixin-zhang",500);                             		//�����ͼ����֣�������
							map_skill("strike","cuixin-zhang");
							nw_parry="cuixin-zhang";
							prepare_skill("strike", "cuixin-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.cuixin" :)});
							set("f_skill","cuixin-zhang");       							//������pfm�����Ķϳ�
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("yinlong-bian",500);                                 //�����ͼ�����������������
							map_skill("whip","yinlong-bian");
							w_parry="yinlong-bian";
							u_pfm=u_pfm + ({(: perform_action, "whip.chanrao" :)});   	   //����������pfm�����ƾ�
							u_pfm=u_pfm + ({(: perform_action, "whip.feilong" :)});        //����  
							u_weapon="whip";
							set("f_w_skill","yinlong-bian");
						break;
					}
				break;
				case 1:
					switch(random(3))
					{
						case 0:
							set_skill("jiuyin-shenzhang",500);								//�����߼����֣���������
							map_skill("strike","jiuyin-shenzhang");
							nw_parry="jiuyin-shenzhang";
							prepare_skill("strike","jiuyin-shenzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.shenzhang" :)});   //��������pfm�����ƶ���
							u_pfm = u_pfm + ({(: perform_action, "strike.yinyang" :)});		//����˫��   
							set("f_skill","jiuyin-shenzhang");     
  						break;
  						case 1:
							set_skill("jiuyin-shenzhua",500);								//�����߼����֣�������צ
							map_skill("claw","jiuyin-shenzhua");
							nw_parry="jiuyin-shenzhua";
							prepare_skill("claw","jiuyin-shenzhua");
							u_pfm = u_pfm + ({(: perform_action, "strike.sanjue" :)});      //������צpfm����������צ
							set("f_skill","jiuyin-shenzhua");
  						break;
   						case 2:
							set_skill("dafumo-quan",500);								    //�����߼����֣����ħȭ
							map_skill("cuff","dafumo-quan");
							nw_parry="dafumo-quan";
							prepare_skill("cuff","dafumo-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});     		//���ħȭpfm����ħ 
							set("f_skill","dafumo-quan");
  						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("xuanyin-jian",500);									//�����߼���������������	
							map_skill("sword","xuanyin-jian");
							w_parry="xuanyin-jian";
							u_pfm = u_pfm + ({(: perform_action, "sword.xuanyin" :)});      //��������pfm�������� 	
							u_pfm = u_pfm + ({(: perform_action, "sword.zhan" :)});			//ն�־�	
							u_weapon="sword";
							set("f_w_skill","xuanyin-jian");
						break;
					}					
				break;	
				}
			break;//end case 9y		
			case "hmg":
				set("family/family_name","��󡹦����");		
				set_skill("hamagong",500);
				map_skill("force","hamagong");
				map_skill("strike","hamagong");
				prepare_skill("strike","hamagong");
				nw_parry="hamagong";
				set("oyf/hamagong",3);
				u_pfm = u_pfm + ({(: perform_action, "strike.hama" :)});        	
				u_pfm = u_pfm + ({(: exert_function, "nizhuan" :)});        	
				set("f_skill","hamagong");
 		
			break;//end hmg
			case "pxj":
				set("family/family_name","�������ܵĴ���");		
				set_skill("pixie-jian",500);
				set_skill("hanbing-zhenqi",500);					//��ɽ�ڹ�����������			
				map_skill("force", "hanbing-zhenqi");
				map_skill("dodge", "pixie-jian");
				map_skill("sword", "pixie-jian");
				u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //��������pfm������
				u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //�ۺ�
				u_pfm = u_pfm + ({(: perform_action, "sword.cimu" :)});        	
				u_pfm = u_pfm + ({(: perform_action, "dodge.feiying" :)});        	
				u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        	
				w_parry="pixie-jian";
				u_weapon="xiuhua";
				set("f_w_skill","pixie-jian");
			break;//end pxj
			case "jsj":
				set("family/family_name","���߽����Ĵ���");		
				set_skill("zixia-gong",500);								//��ɽ�ڹ�����ϼ��
				set_skill("huashan-shenfa",500);							//��ɽ�Ṧ����ɽ��				
				set_skill("jinshe-jianfa",500);
				set_skill("jinshe-zhangfa",500);
				map_skill("force","zixia-gong");
				map_skill("dodge","huashan-shenfa");
				map_skill("sword","jinshe-jianfa");
				map_skill("strike","jinshe-zhangfa");
				prepare_skill("strike","jinshe-zhangfa");
				nw_parry="jinshe-zhangfa";
				w_parry="jinshe-jianfa";
				set("f_w_skill","jinshe-jianfa");
				set("f_skill","jinshe-zhangfa");
				u_weapon="sword";
				u_pfm = u_pfm + ({(: perform_action, "sword.kuangwu" :)});        	

				
			break;//end jsj
	}//end whole switch


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
	u_pfm = u_pfm + ({(: perform_action, "blade.duan" :)});        	
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
	set("chat_msg_combat", u_pfm);
}

//��¼obejct���õĿ����мܺͱ����м��Լ�ʹ�õ�����������Ҫ�ı�ʱ���Ե���
set("w_parry",w_parry);
set("nw_parry",nw_parry);
set("u_weapon",u_weapon);

return 1;
}
