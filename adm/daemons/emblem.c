// card.c �̿�
// Created by Numa 19990828 & Will Modify then and then...
// Bcz my alias too long can't .......
// add by tangfeng

#define S_VISION "Version 2.0��"
#define COPY_NPC "/tmp/tangfeng/shield_npc"
#include <ansi.h>
#include <command.h>
#include <login.h>
#include <armor.h>  
//#include <combat.h>

inherit SHIELD;
#include <combat_msg.h>
string setcolor();
int copy_skill(object me, object ob);
int update_player(object me);
//void mofa_start(object me,string color);
void mofa_damage(string type,object me,object ob,int i);
//void zhaohuan_fight(object obj,object me);
void create()
{
        set_name(HIY"��֮����"NOR,({"fire emblem","emblem","fire"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  
        set("long",HIR"��ʦר����Ʒ\n"NOR);
        set("unit","ö");
        set("value",100000);
        seteuid(getuid());
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
	set("material", "steel");                 
        set("armor_prop/armor", 200);
        }
       
        setup();
}

void init()
{
        object me = this_player();
        
        if (me && present(this_object(), me))
        {
                add_action("help","help");//����
		add_action("do_qidong","qidong");//������ǿ����
		add_action("do_qu","qu");//ȥ�κεط�						
		add_action("do_kan","kan");//�쿴
		add_action("do_mingling","ml"); //����   
		add_action("do_whohave","wh");//�쿴��Ʒ
		add_action("do_di","di");//�쿴���
		add_action("do_cip","cip");//�쿴ip
		add_action("do_call","hj");//call
		add_action("do_cplayer","cplayer");//copy��ҵ�һ��npc
		add_action("do_cnpc","cnpc");//�����趨һ��npc
		add_action("do_cparty","cparty");//�����趨�Լ�һ�������书
		add_action("do_cskill","cskill");//����copy���skills					
		add_action("add_spel_skill","askill");//����copy���skills
		wear();        
        }
        
}

int query_autoload()
{
        if (wizardp(environment())) return 1;
        return 0;
}

int help(string arg)
{
        if (arg == "emblem")
        {
                write("        
Ŀǰ���õ������У�        
����                 ����                          ��;            
��������������������������������������������������������������������������������
qidong  (qidong ok/qidong none)             [������˵�еĳ��ܶ���]
qu      (�����������������趨��[help qu])   [ȥ�κ���ȥ�ĵط���]
kan     (��������ƻ���)                  [����ֱ�Ӳ鿴���ﵵ��]
ml      (Npc��Id)       (Ҫִ�е�����)      [����ֱ����Npcִ��ָ��]
wh      (��Ʒ��Id)                          [ֱ�Ӳ���������Ʒ����]
di      (�ڶ�ֵ[help di])                   [���Զ�������Ͻ��жԱ�]");
    	write("
cip     (Ip��ַ)                            [��ҵ�ַ���鿴]
hj      (���)->(����)(����)                [���Ժ���Npc�����Ǻ�]
cplayer (���Id)                            [���Ը�����ҽ��в���]
cnpc    (���ɡ��ȼ���[help cnpc])           [�������⸴��һ���ε�¥Npc]
cparty  (id,���ɡ��ȼ�[help cparty)         [���Է�����趨�Լ����������书]
cskill  (���)                              [��������copy��ҵ��书]
��������������������������������������������������������������������������������        
                                     ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR
        );
        return 1;
        }
        
        if (arg == "qu")
        {
                write(@QU
        
        Ŀǰ���趨��λ�ã�
        
        th      �һ�������ͤ                    /d/thd/jicui.c
        gy      ����ׯǰ��                      /d/thd/guiyun/qianting.c
        nj      ţ�Ҵ�С��                      /d/thd/niujia/xiaodian.c
        mj      ���̹�����                      /d/mingjiao/gmd.c
        tl      �����°�ʯ·                    /d/tls/road.c
        gb      ؤ����ŷֶ�                    /u/explorer/gb/fenduo1.c
        gm      ��Ĺ�����                      /d/gumu/rukou.c
        mr      Ľ��������                      /d/mr/yanziwu.c
        xs      ѩɽ��ǰ�㳡                    /d/xueshan/guangchang.c
        fm      �����·�ħȦ                    /d/shaolin/fumoquan.c
        hs      ��ɽǰ��                        /d/huashan/qianting.c
        sl      ������ƽ̨                      /d/shaolin/pingtai.c
        xy      ��������·��                    /d/xiangyang/cross2.c
        wg      ������ݴ�Ժ                    /d/wuguan/dayuan.c
        wd      �䵱�������                    /d/wudang/sanqing.c
        ss      ��ɽ����̨                      /d/songshan/fengchantai.c
        yz      ���ݿ͵�                        /d/city/kedian.c
        gc      �ؽ��߲��Թ�                    /d/hj/mg-room2.c
        ms      �һ���Ĺ��                      /d/thd/mudao2.c
        wi      ��ʦ��Ϣ��                      /d/wizard/wizard_room.c
        dl      ����������������                /d/dali/wangfu/damen.c
        em      ����ɽ�����ֹ㳡                /d/emei/huazangangc.c
        sd      ��Ĺ�����                      /d/gumu/jqg/xiaoshi.c
        ld      �������ּ�յ�                  /d/sld/kongdi.c
        xx      ���޺����¶���                  /d/xingxiu/ryd1.c
QU
);
				write("
                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
                return 1;
        }
        
        if (arg == "di")
        {
                write(@DI
        
        Ŀǰ�ڶ��У�
        
        exp                                     [��ʾÿСʱ���þ������1000�������Ϣ]
        expall                                  [��ʾ����������ҵ�ÿСʱ���õľ���ֵ]
DI
);
				write("                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR   
);
                return 1;
        }
        if (arg == "cnpc")
        {
                write(@CNPC
        
�����ʽ		      cnpc |<���ɱ��>|<�Ѷȼ���>|<�����Ƿ�>|
�ڶ�����˵��
���ɱ�ţ�
1�����䵱           2������ɽ           3������ɽ           4������Ĺ
5����ؤ��           6��������           7����������         8����Ľ��     
9����������         10��������          11��������          12��������
13�����һ���        14��������          15��������          16�������� 
17����������ȫ      18������󡹦        19������а��        20�������߽�
�Ѷȼ����� 
1����9
�����趨�� 
1��������           2��������           3�������           4��������+����       
        
CNPC
);
				write("
                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
                return 1;
        }
       if (arg == "cparty")
        {
                write(@CPARTY
        
�����ʽ		      cparty <player id> <����> <skills level>
�ڶ�����˵��
���ɱ�ţ�
wd�����䵱          hs������ɽ          ss������ɽ          gm������Ĺ
gb����ؤ��          tz��������          dls����������       mr����Ľ��     
sld����������       xx��������          em��������          mj��������
thd�����һ���       tls��������         sl��������          kl�������� 
wudu�����嶾��      xiaoyao������ң��   tiandi������ػ�    xuejian����ѩɽ����
        
CPARTY
);
				write("
                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
                return 1;
        }
        
        if (arg == "askill")
        {
                write(@ASKILL
        
�����ʽ	
			askill <player id> <quest���> <skills level>
�ڶ�����˵��
�书��ţ�
			feihu   �ɺ�ȫ��   qzwds    ǧ������
			jsj     ���߽�     hmg      ��󡹦
			9yin1   ������     9yin2    ����ȫ
			lbwb    �貨΢��   szj      ���Ǿ�ȫ��     
        
ASKILL
);
				write("
                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
        return 1;
		}
}


int do_cskill(string arg)
{
	object ob;
	object me=this_player();
    
	if (!arg)	
		return notify_fail("cskill <player id>\n");

    if (! objectp(ob = present(arg, environment(me))))//�ж϶����Ƿ�������
		return notify_fail("����ǰû������ˡ�\n");

	if (!wizardp(me))//�ж��Ƿ�����ʦ
		return notify_fail("ֻ����ʦ�ſ��Ը��Ʊ��˵��书��\n");
    
	copy_skill(me, ob);//��ʼ���ú���COPY�书��״̬
	message_vision(HIM "$N���������дʣ�ֻ��һ�����������$N��$n��\n" NOR,me, ob);//��ʾ��״̬
	return 1;
}

int copy_skill(object me, object ob)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	if (mapp(skill_status = me->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);//���������Լ��Ĺ�������

		temp = sizeof(skill_status);
		for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);//ɾ���Լ����й���
	}

	if (mapp(skill_status = ob->query_skills()))//�ж϶����Ƿ��й������н��������������ȫ������
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);//�������ж��󹦷�����

		for (i = 0; i < sizeof(skill_status); i++)
			me->set_skill(sname[i], skill_status[sname[i]]);//Ϊ�Լ��������й���
	}

	if (mapp(map_status = me->query_skill_map()))//�ж��Լ��Ƿ�����װ��Ļ�������
	{
		mname = keys(map_status);

		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
			me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))//�ж϶�����װ��Ļ����������н��������������
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
			me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))//�ж��Լ��Ƿ�����װ������⹦��
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
			me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))//�ж϶�����װ������⹦�����н��������������
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();//�õ���������״̬
	my = me->query_entire_dbase();//�õ��Լ�����״̬

	my["str"] = hp_status["str"];//��ʼ����״̬
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	my["max_qi"] = hp_status["max_qi"];
	my["eff_qi"] = hp_status["eff_qi"];
	my["qi"] = hp_status["qi"];
	my["max_jing"] = hp_status["max_jing"];
	my["eff_jing"] = hp_status["eff_jing"];
	my["jing"] = hp_status["jing"];
	my["max_neili"] = hp_status["max_neili"];
	my["neili"] = hp_status["neili"];
	my["jiali"] = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];//��������״̬

	me->reset_action();//��������
	return 1;
}

int do_cparty(string arg)
{
    object ob,me=this_player();
	string party,obj;
	mapping skill;
	string *skl;
	int i,level;
	if( !arg ) 
		return notify_fail(HIY"cparty <obj> <party> <level>\n"NOR);
	if( !arg || sscanf(arg, "%s %s %d", obj, party,level)!=3 )
		return notify_fail(HIR"setskill <obj> <party>  <level>\n"NOR);

	ob = find_player(obj);
	if( !ob )  
		ob = find_living(obj);
	if( !ob )       
		ob = present(obj, environment(me));
	if( !ob )
		return notify_fail("�Ҳ����������.\n");
	if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
	if( userp(ob) && ob->query("no_call") )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
	if (party!="mj" && party!="gb" && party!="wd" && party!="tz" && party!="thd" && party!="hs" &&
		party!="ss" && party!="sl" && party!="dls" && party!="gm" && party!="tls" && party!="sld" &&
		party!="em" && party!="xx" && party!="mr") 
		return notify_fail("no this party.\n");
	if(level<50 && level>9999)
		return notify_fail("the value of level is invalid.\n");

	write(WHT"Begin setting party for "NOR + ob->short(1) + WHT"��\n"NOR);
    
	ob->set("neili",level*level);
	
    
	ob->set("max_neili",level*level/10);
	write(WHT"Setting max_neili "NOR + level*level/10 + WHT"\n"NOR);
	ob->set("eff_neili",level*level/10);
	ob->set("jingli",level*level/20);
	ob->set("max_jingli",level*level/20);
	ob->set("eff_jingli",level*level/20);
	ob->set("qi",level*level/10);
	write(WHT"Setting qi "NOR + level*level/10 + WHT"\n"NOR);
	ob->set("max_qi",level*level/10);
	ob->set("eff_qi",level*level/10);
	ob->set("jing",level*level/10);
	ob->set("max_jing",level*level/10);
	ob->set("eff_jing",level*level/10);
	ob->set("mud_age",1028939);
	ob->set("combat_exp",(level-1)*(level-1)*level/10);
	write(WHT"Setting combat_exp "NOR + (level-1)*(level-1)*level/10 + WHT"\n"NOR);
	ob->delete("enter_wuguan");
    
    ob->set_skill("lingbo-weibu",level);
	skill = ob->query_skills();
	skl = keys(skill);
	i = sizeof(skl);
	write(WHT"Deleting old skills ...\n"NOR);
	while (i--) 
	{
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
    write(WHT"Adding "+party+" skills ...\n"NOR);
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
ob->set("family/family_name",party);
write(WHT"\nDone.\n"NOR);
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
int do_cplayer(string arg)
{
	int i,k;
	object me = this_player();
	object obj,player,*inv;
	string player_id;
	if(me->query_temp("killer")) return 0;
    if(me->is_fighting()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
	if(!arg) return notify_fail(HIR"cplayer id\n"NOR);

	player_id=arg;    
	player=LOGIN_D->find_body(player_id);
	if(!player) player = find_living(player_id);
	if(!player)
		return notify_fail(HIY"û�з���һ��id��"+player_id+"����ҡ���ע����������б�\n"NOR);
	if(player==me)
		return notify_fail(HIY"���ṩ�Բ���������\n"NOR);
	if( wiz_level(me) < wiz_level(player) )
		return notify_fail("��û��ֱ�Ӻ����������ĸ���Ȩ����\n");
	//if(wizardp(player))
	//	return notify_fail(HIY"��ʦ�޷�Ѱ�ң�\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail(HIY"���ﲻ��ս�������޷��ٻ�Player��\n"NOR);
	obj=new(COPY_NPC);
	write(WHT"Confirm player "+player->query("name")+"("+player->query("id")+") ...\n"NOR);
	write(WHT"Copy "+COPY_NPC+" ...\n"NOR);
	obj->do_copy(player);
	write(WHT"Copy skills && items ...\n"NOR);
	obj->set("title",HIY"����Ʒ"NOR);
	if(!random(4))
	{
		obj->set("double_attack",1);
		obj->set_temp("double_attack",1);
		obj->set("title",HIR"����ͻ�临��Ʒ"NOR);
		obj->add("combat_exp",random(obj->query("combat_exp")));
		obj->add("max_qi",random(obj->query("max_qi")*3/2));
		obj->add("max_neili",random(obj->query("max_neili")/2));
		obj->reincarnate();
		obj->set("neili",obj->query("max_neili")*2);
	}
	i=obj->query("combat_exp")/me->query("combat_exp");
	if(i>0)
		obj->set("quest/level",i*i);//

	write(WHT"Copy ok!\n"NOR);

	if(!obj)
		return notify_fail(RED"�������ƺ�ʧЧ��\n"NOR);
	obj->set("jiali",200);
	obj->set("kill_object",me);
	message_vision("$N���������дʣ�ͻȻ˫��һ�ӣ�ֻ��$n���������\n", me, obj);
	obj->move(environment(me)); 
	obj->kill_ob(me);
	me->kill_ob(obj);
	obj->set_leader(me);
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++)
		{
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);          
		} 
	}
	return 1;
}

int do_cnpc(string arg)
{
	string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","mr",
							"sld","xx",	"em","mj","thd","tls","sl","kl","9y","hmg","pxj","jsj"});
	object me = this_player();
	object obj,*inv;
	string player_party;
	int i,p,j,k;
	int a=1,b=0,c=100,d=9,e=0,f=0;
	// a  �߼�/�ͼ��书 b ����/���� c pfm���� d ����ӳ� e hubo f lbwb
	if(me->query_temp("killer")) return 0;
    if(me->is_fighting()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
	if(!arg) return notify_fail(HIR"ָ���ʽ��cnpc |����|����|����|\n"NOR);

	if(sscanf(arg, "|%d|%d|%d|", i, p,j) == 3);
	else return notify_fail(HIR"ָ���ʽ��cnpc |����|����|����|\n"NOR);
	if(i>20 || i<1 || p>9 || p<1 ||j<1 || j>4) 
			return notify_fail(HIY"ָ��������ȡֵ��Χ����ϸ�Ķ��ּ��ϵ���ʾ��\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail(HIY"���ﲻ��ս�������޷��ٻ�Npc��\n"NOR);
	
	if(j==2) b=1;
	else if(j==3) b=random(2);//�����ĸ���
	else if(j==4) e=1;
		
	if(p<=2)
	{
		a=0;//�ͼ��书��
		c=p*30+random(p*30);
		d=9+random(p*3/2);//��ͬ����exp�����Ѷ�����һ��
	}
	else if(p==3)
	{
		c=(p-2)*30+random((p-2)*30);
		d=9+p-2;//����11%exp
		e=random(2);//����hubo
	}
	else if(p==4)
	{
		c=(p-2)*30+random((p-2)*30);
		d=9+p-3+random(p);//����11%~44%exp
		e=random(2);//����hubo
	}
	else if(p==5)
	{
		d=9+p-1+random(p-4);//����44%~66%exp
		e=1;//����hubo
		f=random(2);
	}
	else if(p==6)
	{
		d=9+p+random(p-3);//����66%~88%exp
		e=1;//����hubo
		f=random(2);
	}
	else if(p==7)
	{
		d=9+p+1+random(p-3);//����88%~122%exp
		e=1;//����hubo
		f=1;
	}
	else if(p==8)
	{
		d=9+p+3+random(p-3);//����122%~155%exp
		e=1;//����hubo
		f=1;
	}
	else if(p==9)
	{
		d=9+p+5+random(p-3);//����155%~211%exp
		e=1;//����hubo
		f=1;
	}
	if(c>100) c=100;
  	write(WHT"Confirm "+a+"/"+b+"/"+c+"/"+d+"/"+e+"/"+f+"/"+p+" "+"...\n"NOR);

	player_party=str_menpai[i-1];
	obj=new(COPY_NPC);
	write(WHT"Copy "+COPY_NPC+" ...\n"NOR);
	obj->set("quest/level",p);//
	obj->copy_menpai(({player_party}),a,b,c);
	write(WHT"Copy party skills ...\n"NOR);
	obj->set_skills_level((me->query("max_pot")-100)*d/9);	
	obj->copy_state();	
	write(WHT"Copy state ...\n"NOR);
	obj->get_npc_name();	
	if(i<=16)
		obj->set("title",HIW+obj->query("family/family_name")+HIW"����"NOR);
	else obj->set("title",HIY+obj->query("family/family_name")+NOR);
	write(WHT"Change name && title ...\n"NOR);
	if(e==1) obj->set("double_attack",1);
	if(f==1 && i!=13 && i!=17 && i!=19 && i!=4)
	{
		obj->set_skill("lingbo-weibu",(me->query("max_pot")-100)*d/9);
		obj->set("quest/�����˲�/�书/yuxiang",1);
		obj->set("quest/�����˲�/�书/pass",1);
		obj->map_skill("dodge","lingbo-weibu");		
	}
	obj->set("max_qi",me->query("max_qi")*(d+random(3))/9);
	write(WHT"Setting max_qi "NOR + obj->query("max_qi") + WHT"\n"NOR);
	obj->set("eff_qi",obj->query("max_qi"));
	obj->set("qi",obj->query("max_qi"));
	obj->set("max_jing",obj->query("max_qi"));
	obj->set("eff_jing",obj->query("max_qi"));
	obj->set("jing",obj->query("max_qi"));
	obj->set("max_jingli",obj->query("max_qi"));
	obj->set("jingli",obj->query("max_qi"));
	obj->set("max_neili",me->query("max_neili")*(d+random(3))/9);
	write(WHT"Setting max_neili "NOR + obj->query("max_neili") + WHT"\n"NOR);
	obj->set("neili",me->query("max_neili")*(d+random(3))*3/18);	
	obj->set("combat_exp",me->query("combat_exp")*(d+random(2))/9);	
	if((obj->query("combat_exp")-me->query("combat_exp"))>30000000)	
		obj->set("combat_exp",me->query("combat_exp")+30000000);
	write(WHT"Setting combat_exp "NOR + obj->query("combat_exp") + WHT"\n"NOR);
	//��ֹ����������������30M
	obj->set("party_id",i);//���ɺ���


	if(!obj)
		return notify_fail(RED"�������ƺ�ʧЧ��\n"NOR);
	write(WHT"Copy ok....\n"NOR);
	obj->set("jiali",200);
	obj->set("kill_object",me);
    message_vision("$N���������дʣ�ͻȻ˫��һ�ӣ�ֻ��$n���������\n", me, obj);
	obj->move(environment(me)); 
	obj->kill_ob(me);
	me->kill_ob(obj);
	inv = all_inventory(obj);
	obj->set_leader(me);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++)
		{
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);          
		} 
	}
	return 1;
}

int do_qidong(string arg)
{
        object me = this_player();
        string color;
		color = setcolor();	
        
		if (!arg || arg=="ok")
		{
            if(query("shield"))
				return notify_fail(HIR"���������Ѿ�������\n"NOR);
			set("shield",1);
			message_vision(color+"\n$N���������дʣ�ֻ��$N�����������ֳ��������߲ʹ⻷��\n\n",me);
			return 1;

		}
		else if(arg=="none")
		{
            if(!query("shield"))
				return notify_fail(HIR"�������ƻ�δ��������\n"NOR);
			delete("shield");
			message_vision(color+"\n$N���������дʣ�ԭ����Լ���Ƶ��߲ʹ⻷�������š�\n\n",me);
			return 1;
		}
		else
			return notify_fail(color+me->query("name")+"���������дʣ�������ʲôҲû�з�����\n\n"NOR);		
        return 1;
}
int do_qu(string arg)
{
        object me = this_player();
        object ob;
        int goto_inventory = 0;
        
        if (!arg)
                return notify_fail("��Ҫȥ���\n");
        if (arg == "th") {me->move("/d/thd/jicui.c");return 1;}
        if (arg == "gy") {me->move("/d/thd/guiyun/qianting.c");return 1;}       
        if (arg == "nj") {me->move("/d/thd/niujia/xiaodian.c");return 1;}               
        if (arg == "mj") {me->move("/d/mingjiao/gmd.c");return 1;}
        if (arg == "tl") {me->move("/d/tls/road.c");return 1;}
        if (arg == "gb") {me->move("/u/explorer/gb/fenduo1.c");return 1;}
        if (arg == "gm") {me->move("/d/gumu/rukou.c");return 1;}
        if (arg == "mr") {me->move("/d/mr/yanziwu.c");return 1;}
        if (arg == "xs") {me->move("/d/xueshan/guangchang.c");return 1;}
        if (arg == "fm") {me->move("/d/shaolin/fumoquan.c");return 1;}
        if (arg == "hs") {me->move("/d/huashan/qianting.c");return 1;}
        if (arg == "sl") {me->move("/d/shaolin/pingtai.c");return 1;}
        if (arg == "xy") {me->move("/d/xiangyang/cross2.c");return 1;}
        if (arg == "wg") {me->move("/d/wuguan/dayuan.c");return 1;}             
        if (arg == "wd") {me->move("/d/wudang/sanqing.c");return 1;}
        if (arg == "ss") {me->move("/d/songshan/fengchantai.c");return 1;}
        if (arg == "yz") {me->move("/d/city/kedian.c");return 1;}
        if (arg == "gc") {me->move("/d/hj/mg-room2.c");return 1;}
        if (arg == "ms") {me->move("/d/thd/mudao2.c");return 1;}
        if (arg == "wi") {me->move("/d/wizard/wizard_room.c");return 1;}
        if (arg == "dl") {me->move("/d/dali/wangfu/damen.c");return 1;}
        if (arg == "em") {me->move("/d/emei/huazangangc.c");return 1;}
        if (arg == "sd") {me->move("/d/gumu/jqg/xiaoshi.c");return 1;}
        if (arg == "ld") {me->move("/d/sld/kongdi.c");return 1;}
        if (arg == "xx") {me->move("/d/xingxiu/ryd1.c");return 1;}

        else
        {
                ob = find_player(arg);
                if(!ob)
                        ob = find_living(arg);
                if (!ob)
                        ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob))
                {
                        arg = resolve_path(me->query("cwd"), arg);
                        if( !sscanf(arg, "%*s.c") ) arg += ".c";
                        if( !(ob = find_object(arg)) )
                        {
                                if( file_size(arg)>=0 )
                                        ob = load_object(arg);
                                else return notify_fail("û�������ҡ������ط���\n");
                        }
                }
        if(!goto_inventory && environment(ob))
                ob = environment(ob);
                if( !ob )
                        return notify_fail("������û�л������� goto��\n");
                me->move(ob);
                return 1;
        }
}

int do_kan(string arg)
{
        object me = this_player();
        object obj;
        string file;
        
        if (!arg)
                return notify_fail("ָ���ʽ��kan (here|Npc��)\n");
        seteuid(geteuid(me));
        obj = present(arg, me);
        if (!obj)
                obj = present(arg, environment(me));
        if (!obj)
                obj = find_object( resolve_path(me->query("cwd"), arg) );
        if (!obj)
                return notify_fail("û��������....��\n");
        file = base_name(obj)+".c";
        if(wizardp(me)) 
			write(MAG"�õ������ƣ� " + file + "��\n\n"NOR);
		else 
			write(MAG"����Ʒ���ƣ� " + obj->query("name") + "��\n\n"NOR);
       //if(wizard(me)) 
		    	//write(read_file(file));
        return 1;
}

int do_mingling(string arg)
{
        object me = this_player();
        object obj;
        string tar;
        
        if (!arg)
                return notify_fail("��Ҫ����˭��\n");
        if (sscanf(arg,"%s %s",tar,arg)!=2)
                return notify_fail("ָ���ʽ��ml (Npc��Id) (Ҫִ�е�����)\n");

        seteuid(geteuid(me));   
        obj = present(tar, me);
        if (!obj)
                obj = present(tar, environment(me));
        if (!obj)
                return notify_fail("û��������....��\n");
		if (obj == me)
			    return notify_fail("ֱ�Ӵ�����ȽϿ�Щ��\n");
		if (geteuid(obj) == "tangfeng" 
			|| (userp(obj) && wiz_level(me) < wiz_level(obj)) 
			|| (userp(obj) && !wizardp(me)))
			    return notify_fail(query("name")+NOR+MAG"ͻȻ����һ�����ʣ�����Ҳ�------\n\n"NOR);		
		obj->force_me(arg);
        return 1;
}

int do_whohave(string arg)
{
        object *ulist;
        int i;

        if (!arg)
                return notify_fail ("ָ���ʽ��wh <��Ʒ��Id>\n");

        ulist = users();
		if(!wizardp(this_player()) && random(3))
			return notify_fail(query("name")+NOR+MAG"ͻȻ����һ�����ʣ�����Ҳ�------\n\n"NOR);		

        write ( MAG"������������д���Ʒ��\n\n"NOR);
        write ( HIW" ����            ʦ��            ����      Id          ����\n"NOR);
        write ( HIY"������������������������������������������������������������������������\n"NOR);
        for (i=0;i<sizeof(ulist);i++)
        {
                if (present(arg,ulist[i]))
                {
                        write(sprintf(" %-16s%-16s%-10s%-12s%d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation")));
                }
        }
        write ( HIY"\n������������������������������������������������������������������������\n"NOR);
        write ( "                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
        return 1;
}

int do_di(string arg)
{
        object *ulist;
        mapping my;
        int exp;
        int i;

        if (!arg)
                return notify_fail ("ָ���ʽ��di <�ڶ�ֵ>\n");

        ulist = users();

        if (arg=="exp")
        {
                write ( MAG"������ϡ�ÿСʱ����ֵ����1K�ߡ����£�\n\n"NOR);
                write ( HIW" ����      ʦ��      ����      Id        ����  ����ֵ    ׬ȡֵ/Сʱ\n"NOR);
                write ( HIY"������������������������������������������������������������������������\n"NOR);
                for (i=0;i < sizeof(ulist);i++)
                {
                if (wizardp(ulist[i])) continue;
                        my = ulist[i]->query_entire_dbase();
                        if (ulist[i]->query("combat_exp")<100000) continue;
                        exp = (int)my["combat_exp"]/(((int)my["mud_age"])/3600);
                        if ( exp > 1000)
                        {
                                write(sprintf(" %-10s%-10s%-10s%-10s%-6d%-10d%-6d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation"),ulist[i]->query("combat_exp"),exp));
                        }
                }
                write ( HIY"\n������������������������������������������������������������������������\n"NOR);
                write ( "                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
                return 1;
        }
        if (arg=="expall")
        {
                arg = MAG"������ϡ�ÿСʱ����ֵ�����£�\n\n"NOR;
                arg += HIW" ����      ʦ��      ����      Id        ����  ����ֵ    ׬ȡֵ/Сʱ\n"NOR;
                arg +=  HIY"������������������������������������������������������������������������\n"NOR;
                for (i=0;i < sizeof(ulist);i++)
                {
                if (wizardp(ulist[i])) continue;
                        my = ulist[i]->query_entire_dbase();
                        if (ulist[i]->query("combat_exp")<100000) continue;
                        exp = (int)my["combat_exp"]/(((int)my["mud_age"])/3600);
                        arg +=sprintf(" %-10s%-10s%-10s%-10s%-6d%-10d%-6d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation"),ulist[i]->query("combat_exp"),exp);
                }
                arg += HIY"\n������������������������������������������������������������������������\n"NOR;
                arg += "                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR;
                this_player()->start_more(arg);
                return 1;
        }

        else return notify_fail ("ָ���ʽ��di <�ڶ�ֵ>\n");
}

int do_cip(string arg)
{
        object *ob;
        string msg;
        int i;
        
        if (!arg)
                return notify_fail("ָ���ʽ��cip <Ip��ַ>\n");

        ob = users();

        write(sprintf(MAG"��������"GRN"%s"MAG"��ַ�����ߵ����:\n\n"NOR,arg));
        write ( HIW" ����            ʦ��            ����      Id          ����\n"NOR);
        write ( HIY"������������������������������������������������������������������������\n"NOR);
        for (i=0;i < sizeof(ob);i++)
        {
                if ( arg == query_ip_number(ob[i]) )
                {
                        msg = sprintf(" %-16s%-16s%-10s%-12s%d\n",ob[i]->query("family/family_name"),ob[i]->query("family/master_name"),ob[i]->name(),ob[i]->query("id"),ob[i]->query("family/generation"));
                }
        }
        write(msg + "\n");
        write ( HIY"������������������������������������������������������������������������\n"NOR);
        write ( "                                                ��������������By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
        return 1;
}

int do_call(string arg)
{
        string objname, func, param, euid;
        object obj;
        mixed *args, result;
        int i;
        object me = this_player();
		if(!wizardp(me))
			return notify_fail(query("name")+NOR+MAG"�������������������������ʲô���⡣\n\n"NOR);		

        if( arg )
        {
                if( sscanf(arg, "-%s %s", euid, arg)==2 )
                {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("�㲻���趨�Լ��� euid��\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("ָ���ʽ��hj <���>-><����>( <����>, ... )\n");
        }
        else
                return notify_fail("ָ���ʽ��hj <���>-><����>( <����>, ... )\n");

        obj = present(objname, environment(me));
        if (!obj)
        	obj = present(objname, me);
        if (!obj)
        	obj = find_player(objname);
        if (!obj
        || !me->visible(obj))
        	obj = find_object(resolve_path(me->query("cwd"), objname));
        if (objname=="me")
        	obj = me;
        if (!obj)
        	return notify_fail("�Ҳ���ָ���������\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++)
        {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}
mixed ob_hit(object target, object me, int damage)
{
	string color;


	if(query("shield")) 
	{
		
		color = setcolor();	
		if(random(2))
			message_vision(query("name")+color+"ͻȻ����ҫ�۵Ĺ�â���ֵ���$N"+color+"�����ҹ��ƣ�\n"NOR,target);
		else
			message_vision(query("name")+color+"ͻȻ����һ����͵ľ����ͳ�����$N"+color+"�Ľ�����Ϊ���У�\n"NOR,target);
		return -(8000+damage);
	}
	
}

string setcolor()
{
	int lvl;
	string color;

	lvl = random(15);
	switch (lvl)  {
		case  0:
		case  1:
		case  2: color = HIW;break;
		case  3:
		case  4: color = HIC;break;
		case  5:
		case  6: color = CYN;break;
		case  7:
		case  8: color = HIB;break;
		case  9:
		case 10: color = BLU;break;
		case 11:
		case 12: color = HIM;break;
		case 13: color = MAG;break;
		default: color = HIW;
	}
	//set("name" , color+"���ܶ���"NOR );
	return color;
}

int add_spel_skill(string arg)
{
    object ob,me=this_player();
	string party,obj;
	int level;
	if( !arg ) 
		return notify_fail(HIY"cparty <obj> <quest> <level>\n"NOR);
	if( !arg || sscanf(arg, "%s %s %d", obj, party,level)!=3 )
		return notify_fail(HIR"setskill <obj> <quest>  <level>\n"NOR);

	ob = find_player(obj);
	if( !ob )  
		ob = find_living(obj);
	if( !ob )       
		ob = present(obj, environment(me));
	if( !ob )
		return notify_fail("�Ҳ����������.\n");
	if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
	if( userp(ob) && ob->query("no_call") )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");

	if (party!="9yin1" && party!="9yin2" && party!="lbwb" && party!="szj" && party!="hmg" && party!="qzwds" &&
		party!="jsj" && party!="feihu" ) 
		return notify_fail("no this quest skills.\n");
	if(level<50 && level>9999)
		return notify_fail("the value of level is invalid.\n");

	write(WHT"Begin setting quest skills for "NOR + ob->short(1) + WHT"��\n"NOR);
	if(!wizardp(me))
		return notify_fail(HIY"ͻȻ"+this_object()->query("name")+HIY"��Ȼð��һ�����.\n"NOR);
    
    
    write(WHT"Checking old skills ...\n"NOR);

	ob->set_skill("literate",me->query("int")*10);
	ob->set_skill("poison",200);
	ob->set_skill("wuxing-zhen",200);
	ob->set_skill("medicine",200);
    write(WHT"Adding "+party+" skills ...\n"NOR);
	if(party=="9yin1")
	{
        ob->set("quest/jiuyin2/pass",1);//��־
        ob->set_skill("cuixin-zhang", level);
        ob->set_skill("jiuyin-baiguzhua", level);
        ob->set_skill("yinlong-bian",level); 
        ob->set_skill("jiuyin-shenfa",level/2);   
	}
	if(party=="9yin2")
	{
        ob->set("quest/jiuyin1/owner",1);//��־
        ob->set_skill("daode-jing", level);
        ob->set_skill("jiuyin-zhengong", level);
        ob->set_skill("xuanyin-jian",level);   		
	}
	if(party=="hmg")
	{
        ob->set("oyf/hamagong",2);//��־
        ob->set_skill("hamagong", level);
	}
	if(party=="lbwb")
	{
        ob->set("quest/�����˲�/�书/yuxiang",1);//��־
		ob->set("quest/�����˲�/�书/pass",1);//��־
        ob->set_skill("lingbo-weibu", level);
	}
	if(party=="jsj")
	{
        ob->set_skill("jinshe-jianfa",level);
        ob->set_skill("jinshe-zhangfa",level);        
        ob->set_skill("poison",300);
        ob->set_skill("qianzhu-wandushou",level);
	}
	if(party=="qzwds")
	{
        ob->set("quest/qianzhu/pass",1);
        ob->set_skill("qianzhu-wandushou",level);
	}
	
	if(party=="szj")
	{
        ob->set("quest/���Ǿ�/�书/shenzhao",3);
        ob->set_skill("qianzhu-wandushou",level);
        ob->set_skill("tangshi-jianfa",level);
        ob->set_skill("yangjia-qiangfa",level);
	}
	if(party=="feihu")
	{
        ob->set("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach",1);
        ob->set("quest/ѩɽ�ɺ�/�书/hujiadaofa",1);
        ob->set("quest/ѩɽ�ɺ�/�书/ronghe",1);
        ob->set("quest/ѩɽ�ɺ�/�书/miaojiajianfa",1);
        ob->set_skill("lengquan-shengong",level);
        ob->set_skill("hujia-daofa",level);
        ob->set_skill("miaojia-jianfa",level);
	}
    /*
	switch(party){
	  case "feihu":party=HIY"�ɺ�����"NOR;break;
  	  case "9yin2":party=HIR"��������"NOR;break;
	  case "hmg":party=HIW"ŷ���崫��"NOR;break;
	  default:party="";
	}
	if(party && party!="")
		ob->set("family/family_name",party);
	write(WHT"\nDone.\n"NOR); */
	update_player(ob); 
	return 1;
}

int unequip()
{
	object ob = environment();

	if (ob && userp(ob))
		return notify_fail("������������Ͱ�������(dest)�ɡ�\n");

	return ::unequip();
}
