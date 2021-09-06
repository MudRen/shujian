//update by cool 98.2.18
//added by tangfeng 2004
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"
#define QUESTDIR6 "quest/�����˲�/�书/"

string askduanyu();
string tianlonghelp();
string asksave();
string askxiaofeng();
string askjiumozhi();

int ask_xingyue(object who);
//string ask_liumai1();
string ask_liumai2();
int ask_dudan(object who);   

void create()
{
	object ob;
        set_name("���ٳ���", ({ "kurong zhanglao","kurong","zhanglao"}) );
        set("nickname", "�����³���");
	set("long", 
" ���ٳ�����������֮������ߵ�һ����ɫ����
Ƥ���⻬������Ӥ�����ұߵ�һ��ȴ��ݹǣ�����
һ�Ž��Ƶ���Ƥ֮��ȫ�޼��⣬��ͷͻ�˳�������
Ȼ���ǰ�����ù�ͷ�������������б�����ߣ���
������ο�������ʮ�꣬��������ɮ�ڣ�˭Ҳû��
��������Ŀ��\n");
        set("gender", "����" );
        set("class","bonze");   
        set("unique", 1);
        set("age", 99);
        set("str", 30);
        set("cor", 27);
        set("cps", 32);
        set("int", 35);
        set("per",23);

        set("max_jing",5000);
        set("eff_jingli", 6500);
        set("max_qi", 9500);
        set("jiali",100);
        set("neili",17000);
        set("max_neili",17000); 
        set("rank_info/respect", "��ɮ");
        create_family("������", 12, "ɮ��");
        set("combat_exp", 4350000);
        set("score", 0);

        set("chat_chance_combat", 80);
        set("chat_msg_combat",({ 
                (: exert_function, "ku" :),
                (: perform_action, "finger.sanmai" :),
                (: perform_action, "finger.sandie" :),
        }));
        set_skill("parry", 340);
        set_skill("dodge", 340);
        set_skill("force", 360);
        set_skill("finger", 350);
        set_skill("whip", 320);
        set_skill("liumai-jianzhen",200);
        set_skill("cihang-bian", 320);
        set_skill("duanjia-jianfa", 300);
        set_skill("sword", 300);
        set_skill("strike", 340);
        set_skill("buddhism", 200);
        set_skill("literate", 200);
        set_skill("qiantian-yiyang", 220);
        set_skill("liumai-shenjian", 40);
        set_skill("kurong-changong", 360);
        set_skill("qingyan-zhang", 280);
        set_skill("yiyang-zhi", 340);
        set_skill("tianlong-xiang", 340);

        map_skill("whip", "cihang-bian");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "kurong-changong");
        map_skill("finger", "yiyang-zhi");
        map_skill("strike","kurong-changong");
        map_skill("force", "kurong-changong");
        prepare_skill("finger","yiyang-zhi"); 

        set_temp("apply/armor", 60);
        set_temp("apply/attack", 60);
        set_temp("apply/damage", 60);

        set("inquiry", ([
		"name": "ƶɮ���ǿ���",
		"����" : (: ask_xingyue :),
		"����" : (: ask_dudan :),
		"���ƶ�" : (: ask_liumai2 :),
		//"����" : (: ask_liumai1 :),
            		"����" : (: askduanyu :),
		            "����" : "������Ǵ���",
		            "������" : "�������������£�����μ���ѧ�����֮�ء�",
		            "��������" : (: tianlonghelp :),
		            "Ӫ��" : (: asksave :),
		            "���" : (: asksave :),
		            "����" : "�����˳���Ľ�ݡ������壬�˵�һ���ú���",
		            "Ӫ�ȶ���" : (: asksave :),
		            "Ӫ������" : (: askxiaofeng :),
		            "Ľ�ݸ�" : "�����˳���Ľ�ݡ������壬��˵Ľ�ݹ����꼶���ᣬȴ����������",
		            "Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		            "�Ħ��" : (: askjiumozhi :),
		            "������" : "��˵������������߾�ѧ����Ҫ���������������á�",
	]));

        set("env/һ��ָ", 3);
        setup();
        
        if (clonep(this_object())) {
		if (ob = carry_object("/clone/weapon/xingyue"))
		ob->wield(); 
	}
	carry_object("/d/tls/obj/jiasha")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

void reset()
{
	object ob;
	if (clonep() && (ob = unew(BINGQI_D("xingyue")))) {
		ob->move(this_object());
		command("wield xingyue puti");
        }
}

#include "kurong.h"

string askjiumozhi()
{
	object me;
	me = this_player();
	if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵�������µ�һ��ɮ�Ħ�ǽ����������·𷨽����������Ҵ���֮�Ұ���";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh");
  	  command("? "+me->query("id"));
		  return "��ħɮ��Ȼ����۸��Ҵ������ˣ���Ϊ��ެ����һ�𷨸�ɮ��";
  }
	if (me->query(QUESTDIR2+"start")&& me->query(QUESTDIR2+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "�Ħ����Ϊ�����һ�𷨸�ɮ����ν����������ȫ��һ�ɺ��ԡ�";
  }
  /*
  ���������Ħ������ެ���Ļ�����������ֻ��˵���ߴ��ǻۣ���ͨ�𷨣�ÿ�����꣬��̳����˵�����������ø��صĸ�ɮ��£�
  �Ƽ���ѩɽ�����£�ִ�����ѣ������ڵ䣬�ŷ��ȱϣ��޲���ϲ��̾��ȥ��
  */
  command("nod");
	return "���������Ħ������ެ���Ļ�������������˵���ߴ��ǻۣ���ͨ�𷨣������书Ҳ�Ǿ��ˡ�";
}
string askxiaofeng()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR3+"start"))
  {
  	  command("hoho");
  		return "�����˳���Ľ�ݡ������壬�˵�һ���ú�������Ԯ��֮˵��";
  }
	if (me->query(QUESTDIR3+"start") && !me->query(QUESTDIR3+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }

	if (me->query(QUESTDIR3+"bad"))
	{
  	  command("heng");
  	  command("? "+me->query("id"));
		  return "�Ƿ壬�Ѳ��������ȳ���ԭ��������ν��Ȳ�֪���⣡";
  }
	if (me->query(QUESTDIR3+"start") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR4+"start"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR4+"start")&& !me->query(QUESTDIR4+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR4+"start") && me->query(QUESTDIR4+"over"))
	{
  	  command("haha "+me->query("id"));
		  return "��˵��һս��"+me->query("name")+"�����������֣��˵���������";
  }
  command("hoho");
	return "�����˳���Ľ�ݡ������壬�˵�һ���ú�������Ԯ��֮˵��";
}
string asksave()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR1+"start") &&!me->query(QUESTDIR2+"start"))
  {
  	  command("hoho");
  		return "С����������ϲ��ѧ��ֻ�����׾���ƽ�׽��ˣ�����Ԯ��֮˵��";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵��ǰ��ʱ��С���Ӻ����������ǳ���һ��������δ�лؼң���֪"+RANK_D->query_respect(me) +"�ɷ��������һ�¡�";
  }
	if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ���ֻ���Դ���ٹȻ�����С���Ӿ����㱣���֪���кζ������ܺ������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ���С��������ٹȻ�����������Ѫ�������������죬�ű�������������������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ�����Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
  }
  command("hoho");
	return "С����������ϲ��ѧ��ֻ�����׾���ƽ�׽��ˣ�����Ԯ��֮˵��";
}
string askduanyu()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR1+"start" )&&!me->query(QUESTDIR2+"start"))
  {
  	  command("hoho");
  		return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ���ֻ��������ϲ��ѧ��ֻ�����׾���";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵��ǰ��ʱ��С���Ӻ����������ǳ���һ��������δ�лؼҡ�";
  }
	if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ�����л"+RANK_D->query_respect(me) +"���С���ӡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ���С��������ٹȻ�����������Ѫ�������������죬�ű���������������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ�����Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
  }
  command("hoho");
	return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ���";
}
string tianlonghelp()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR1+"over"))
  {
  	  command("haha");
  		return "���������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
  }
	if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵�������¸�ɮ�Ħ�ǲ��ս����������£���֪��ϲ�ǻ���";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("heng");
		  return "�ҷ�ȱ�����ħɮ��Ȼ����۸��Ҵ������ˣ���Ϊ��ެ����һ�𷨸�ɮ��";
  }
	if (me->query(QUESTDIR2+"over"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ�����л"+RANK_D->query_respect(me) +"�����ⳡ����Σ���������Ҵ���С���ӵ��Խ�ȡ�";
  }
  command("hoho");
	return "�ҷ�ȱ������������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
}
/*
string ask_liumai1()
{
        object ob;
        ob=this_player();

	if( ob->query("dali/meet_dy1")||ob->query("liumai_update")){
		ob->set_temp("liumai/update",1);
		return "��������汣��,����ǰ�ձ���ѩɽ���������Ħ�Ǹ�ץ���ˣ�\n"+
			"�������Դ��񣬶��ܷ��׻����������ӷ�! \n";
	}
	else if( ob->query("dali/meet_dy2")){
		return "��˵�����Ѿ����˴�Ȼ����ˣ��������Ұ��������ӷ� \n";
	}
	return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ��� \n";
}
*/