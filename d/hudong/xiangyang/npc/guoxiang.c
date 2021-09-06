inherit NPC;
int ask_job();
int ask_lineup();
int ask_heal();
void create()
{
	set_name("����", ({"guo xiang", "guo", "xiang",}));
	set("long","�����Ƕ����ɿ�ɽ��ʦ�����������ص�Ů�����塣\n");

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("unique", 1);

	set("age", 20);
	set("shen_type", 1);
	set("str", 32);
	set("int", 32);
	set("con", 32);
	set("dex", 40);
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 7500);
	set("max_neili", 6500);
	set("max_jingli",6000);
	set("eff_jingli",6000);
	set("jiali", 50);
set("combat_exp",2400000);
	set("chat_chance_combat", 40);

	set_skill("dacheng-fofa", 180);
	set_skill("linji-jianzhen", 180);
	set_skill("linji-zhuang", 180);
	set_skill("jieshou-jiushi", 180);
	set_skill("huifeng-jian", 180);
	set_skill("sixiang-zhang", 180);
	set_skill("yanxing-daofa", 180);
	set_skill("hand", 180);
	set_skill("lanhua-shou",180);
	set_skill("literate", 180);
	set_skill("strike", 180);
	set_skill("sword", 180);
	set_skill("blade", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("anying-fuxiang", 180);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-daofa");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "sixiang-zhang");
	map_skill("hand", "lanhua-shou");

	set("inquiry", ([
		"�س�": (: ask_job :),
		"����": (: ask_lineup :),
		"����": (: ask_heal:),
	]) );

	prepare_skill("hand", "lanhua-shou");

	create_family("������", 1, "����");

	setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

int ask_job()
{
       object me = this_player();
       if (!me->query_temp("xy/job"))
       {
	       command("say �������ҵ�����ʾ��");
	       return 1;
       }
      if (me->query("family/family_name") != "������")
      {
	       command("say ���ȥָ���ĵص�ɣ������ɹű���Ҫ�����ˣ�");
	       return 1;
      }
      command("say ���Ҫ���󷨣��Ͳ�������͸������ǡ�");
      command("smile");
      me->set_temp("xy/job",2);
      return 1;
}

int ask_lineup()
{
      object me = this_player();
      if (me->query_temp("xy/job")!=2)
      {
	      command("?");
	      return 1;
      }
      command("nod");
      command("lineup with " + me->query("id"));
      return 1;
}

int ask_heal()
{
      object me = this_player();
      if (me->query_temp("xy/job")<2)
      {
	      command("?");
	      return 1;
      }
	command("exert tiandi "+me->query("id"));
	command("nod "+me->query("id"));
      return 1;
}
void init()
{
	object me=this_player();

	::init();
	if (userp(me) && me->query("str")+me->query("int")+me->query("con")+me->query("dex")>80)
	{
		message_vision("һ�����ص���������$N�͵���δ֪�Ŀռ䡣\n",me);
		me->move("/d/xiangyang/lipindian");
	}
}
