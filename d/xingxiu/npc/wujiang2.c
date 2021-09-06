// wujiang.c �佫

#include <ansi.h>
inherit NPC;

string ask_me();
void create()
{
        set_name("�����", ({ "hou junji", "hou", "junji" }));
        set("gender", "����");
        set("age", 45);
        set("str", 35);
        set("int", 19);
        set("con", 30);
        set("dex", 20);
        set("long", "�������������ؽ����������ѧϰ�����������ñ���\n");
        set("combat_exp", 350000);
        set("attitude", "peaceful");
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("eff_jingli", 1000);
	set("jiali", 30);
        set_skill("force", 70);
        set_skill("unarmed", 80);
        set_skill("strike", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("qingmang-jianfa", 80);
        map_skill("sword", "qingmang-jianfa");
        map_skill("parry", "qingmang-jianfa");
        map_skill("parry", "qingmang-jianfa");
        set("inquiry", ([
		"ͨ��" : (: ask_me :),
		"��æ" : (: ask_me :),
        ]));
    set("no_get","�����������˵̫���ˡ�\n");
        setup();
        carry_object(BINGQI_D("gangjian"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
}

void kill_ob(object me)
{
	int i;
	object ob;
	if(!this_object()->is_killing(me->query("id"))){
		command("say �󵨣�");
		command("say ���ˣ���"+me->name()+"����ץ������\n");
		me->add_condition("killer", 15);
		message_vision("���ܵ��佫��ʼ��$N����������\n", me);
		for(i=0; i<2; i++) {
			if(objectp(ob = present("wu jiang "+(i+1), environment(this_object()))))
			ob->kill_ob(me);
		}
	}
	::kill_ob(me);
}

int accept_object(object me, object obj)
{
	int i = me->query("combat_exp")/20000 + me->query_condition("killer") / 2 + me->query("PKS") * 10;

	i *= 10000;
	if (i < 200000) i = 200000;
        if(obj->query("money_id")){
        	if(me->query_condition("killer") && me->query_temp("hou_ask")){
          		if(obj->value() >= i) {
              			command("haha " + me->query("id"));
              			command("whisper "+me->query("id")+" ��ͷ��İɣ�����°��������ϣ�");
              			me->clear_condition("killer");
              			me->delete_temp("hou_ask");
          			log_file("quest/tongji",sprintf("%8s%-10s����%5d ���ƽ�Ӻ������ȡ����ͨ��ʱ�䣬ʵ��%d��\n",
					me->name(1),"("+capitalize(getuid(me))+")", obj->value()/10000, i/10000),me);
				return 1;
              		}
	          	else {
				command("say ����ô��Ǯ�ܸ�ʲô��");
				return 1;
              		}
		}
        	else {
			command("say �ٺ٣��ǾͶ�л�ˣ�");
			return 1;
             	}
      }
      command("hmm " + me->query("id"));
      command("say �Ҷ�"+obj->name()+"��ϡ����");
      return 0;
}

string ask_me()
{
	object me = this_player();
	int i = me->query("combat_exp")/20000 + me->query_condition("killer") / 2 + me->query("PKS") * 10;

	if(!me->query_condition("killer")) return "����ʲôæ�����ң�";
	if (i < 20) i = 20;
	me->set_temp("hou_ask", 1);
	message_vision(CYN"\n$N����$n�ٺ�һЦ��ɱ���˱�ͨ�����ǰɣ�\n"NOR, this_object(), me);
	command("whisper "+me->query("id")+" "+chinese_number(i)+"���ƽ�");
	return "�취���У����������ٺ٣���Ӧ��֪������ô���ɣ�\n";
}
