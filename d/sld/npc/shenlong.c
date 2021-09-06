inherit NPC;

void kuser();

void create()
{
	set_name("�������", ({ "shen long", "shenlong" }) );
	set("race", "Ұ��");
	set("age", 20);
	set("long", "һ������ˮͰ�ľ��ߣ�����ʮ�ɣ����в��ϵ����Ŷ���\n");
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "twist", "bite" }) );

	set("combat_exp", 200000);
	set("max_qi",5000);
	set("max_jing",5000);

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 400);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 400);
	call_out("kuser",5);
	setup();
}

private void hehe(object me)
{
	if (!me)
		return;
	if (living(me)) {
		tell_object(me, "��ͻȻ����һ��ѣ�Σ�ԭ������Ϊ�������������մ���˾޶���");
		me->unconcious();
	} else
		me->receive_wound("jing", me->query("max_jing")/3, "�޶�����");
}

void init()
{
	object me = this_player();

	::init();
	if (environment() == me)
		call_out((: hehe :), 20, me);
}

void kuser()
{
      object *ob,me;
      int i;

      me=this_object();
      if (!environment(me))
	return;
      ob = all_inventory(environment(me));
      for(i=0;i<sizeof(ob);i++)
      {
          if(userp(ob[i]) && !wizardp(ob[i]))
	  {
          	me->kill_ob(ob[i]);
		ob[i]->kill_ob(me);
	  }
      }
      call_out("kuser",5);
}

void die()
{
	object ob1,ob2,who;
	message_vision("$N�ҽ��������������˼��¾Ͳ����ˡ�\n", this_object());
	ob1 = new(__DIR__"obj/sl_dan");
	ob1->move(environment(this_object()));
	who=this_object()->query_temp("last_damage_from");
	if(objectp(who)){
		if(!objectp(ob2 = unew(__DIR__"obj/sl_cloth")))
			ob2 = new(__DIR__"obj/sl_pi");
		ob2->set_temp("owner",who);
		ob2->move(who);
	}
	if(objectp(who) && userp(who) && living(who) && who->query_temp("marks/hant"))
		who->set_temp("marks/dragon",1);

	destruct(this_object());
}
