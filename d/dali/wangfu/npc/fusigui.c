// fusigui.c
// Modify By River 98/12
// Modify by Lklv 2001.10.23
// make him job_npc
// Modify by tangfeng@SJ 2004

#include <ansi.h>
inherit NPC;

#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"

string ask_join();
string askduanyu();
string tianlonghelp();
string asksave();
string askxiaofeng();
string askjiumozhi();

void create()
{
	set_name("��˼��", ({ "fu sigui", "fu", "sigui" }));
	set("title", "��������������ҽ�");
	set("gender", "����");
	set("age", 33);
	set("str", 25);
	set("unique", 1);
	set("dex", 25);
	set("long", "��������������ʮ���꣬�����������ֳ�һ����ͭ����\n");
	set("combat_exp", 400000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("no_ansuan", 1);
	set("no_bark", 1);
	
	set("job_npc",1);

	set_skill("strike", 60);
	set_skill("club",90);
	set_skill("qiantian-yiyang", 100);
	set_skill("tianlong-xiang", 100);
	set_skill("qingyan-zhang", 80);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("weituo-gun", 100);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);

	map_skill("force", "qiantian-yiyang");
	map_skill("strike", "qingyan-zhang");
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "qingyan-zhang");
	map_skill("club", "weituo-gun");
	prepare_skill("strike","qingyan-zhang");

	set("max_qi", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 20);
	set("inquiry",([
		"��ٸ�" : (: ask_join :),
		"join" : (: ask_join :),
		"����" : (: askduanyu :),
		"����" : "������Ǵ���",
		"������" : "���������Ҷμ���ѧ�����֮�ء�",
		"��������" : (: tianlonghelp :),
		"Ӫ��" : (: asksave :),
		"���" : (: asksave :),
		"����" : "�����˳���Ľ�ݡ������壬�˵�һ���ú���",
		"Ӫ�ȶ���" : (: asksave :),
		"Ӫ������" : (: askxiaofeng :),
		"Ľ�ݸ�" : "�����˳���Ľ�ݡ������壬��˵Ľ�ݹ����꼶���ᣬȴ����������",
		"Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"�Ħ��" : (: askjiumozhi :),
		"������" : "��˵������������߾�ѧ���ҹ����Ⱳ��Ҳδ�ܼ�����",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		CYN"��˼��˵�������������������º��ܣ�������������鷸�ƣ���Ϊ�����С�����ǿɲ������ɡ� ��\n"NOR,
	}));

	setup();
	carry_object("/d/dali/wangfu/npc/obj/tonggun")->wield();
	carry_object("/d/dali/npc/obj/zipao")->wear();
}
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
		  return "��ħɮ��Ȼ����۸��Ҵ������ˣ�ʲô��ެ����һ�𷨸�ɮ����P��P��";
  }
	if (me->query(QUESTDIR2+"start")&& me->query(QUESTDIR2+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "�Ħ����Ϊ�����һ�𷨸�ɮ����ν����������ȫ��һ�ɺ��ԡ�";
  }
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
		  return "��˵������飬ֻ���漰�����������֮������֪��������ô����";
  }

	if (me->query(QUESTDIR3+"bad"))
	{
  	  command("heng");
  	  command("? "+me->query("id"));
                  return "���壬�Ѳ��������ȳ���ԭ��������ν��Ȳ�֪ʲô��˼�������ʣ�";
  }
	if (me->query(QUESTDIR3+"start") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR4+"start"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���漰�����������֮������֪��������ô����";
  }
	if (me->query(QUESTDIR4+"start")&& !me->query(QUESTDIR4+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "��������С���ӵ����֣���ȻҪ�ȡ���λ"+RANK_D->query_respect(me) +"������һ��������Һ��Ҽ�С����һ��Ԯ����";
  }
	if (me->query(QUESTDIR4+"start") && me->query(QUESTDIR4+"over"))
	{
  	  command("haha "+me->query("id"));
		  return "��һս����ʹ�죬"+me->query("name")+"�����������֣��˵���������";
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
		  return "����̽����С���ӱ���ٹ���������ֻ�������������ˣ�ƽ�˹��յ���ٹȡ�";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "��л"+RANK_D->query_respect(me) +"���С���ӣ�ֻ���Դ���ٹȻ�����С���Ӿ����㱣���֪���кζ������ܺ������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "С��������ٹȻ�����������Ѫ�������������죬�ű������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "��Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
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
  		return "С����������ϲ��ѧ��ֻ�����׾���";
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
		  return "����̽����С���ӱ���ٹ�����������ٹ�ʲô�ط�����";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "��л"+RANK_D->query_respect(me) +"����Ҽ�С���ӡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "С��������ٹȻ�����������Ѫ�������������죬�ű������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "��Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
  }
  command("hoho");
	return "��������������֮�ӡ�";
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
  	  command("sigh");
		  return "��ħɮ��Ȼ����۸��Ҵ������ˣ�ʲô��ެ����һ�𷨸�ɮ����P��";
  }
	if (me->query(QUESTDIR2+"over"))
	{
  	  command("thank "+me->query("id"));
		  return "��л"+RANK_D->query_respect(me) +"�����ⳡ����Σ���������Ҵ���С���ӵ��Խ�ȡ�";
  }
  command("hoho");
	return "���������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
}
string ask_join()
{
	object ob = this_player();

	if (ob->query("combat_exp")<3000)
		return ("����书̫�ʲôҲ�����˵ġ�\n");
	if (ob->query_temp("dali_join"))
		return RANK_D->query_respect(ob) + "�Ѿ��Ǳ���������ˣ��ιʻ�Ҫ��������Ц��";
	if (ob->name() != ob->name(1)) {
		command("hmm " + ob->query("id"));
		return RANK_D->query_respect(ob) + "����������Ŀʾ�ˣ�������ı�߾Ͱɣ�";
	}
	ob->set_temp("dali_join",1);
	command("look "+ob->query("id"));
	return "�ã�������λ"+RANK_D->query_respect(ob)+"����Ϊ�����������ˡ�";
}

void kill_ob(object ob)
{
	mixed *local;
	object me = this_object();

	local = localtime(time() * 60);

	if ( local[2] >= 5 && local[2] < 20) {
		command("say ������Ҫ������û���������棡"); 
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
}

int accept_fight(object ob)
{
	mixed *local;
	local = localtime(time() * 60);

	if ( local[2] >= 5 && local[2] < 20) {
		command("say ������Ҫ������û���������棡");
		return 0;
	}
}
