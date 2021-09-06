// mei.c ÷����
// Modified by Darken/Numa@SJ for taohua quest

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "÷����" ,({ "mei chaofeng", "mei" }));
	set("title", "�ڷ�˫ɷ");
	set("nickname", HIB"��ʬ"NOR);
	set("gender", "Ů��");
	set("age", 32);
	set("long",
		"÷�����ǻ�ҩʦΨһ��Ů���ӣ��������ܻ�ҩʦ�۰�����ϧ����ʦ�ֳ�����\n"
		"������㺣�����͵�ˡ������澭�¾�˽����\n"
		"����ɫ�����Ϊ�þӺ����Ե���ڣ�ģ��ȴ��Ϊ�����������һ��������Ⱦ�ͨ�޷���\n");
	set("attitude", "aggressive");

        set("str", 47);
        set("int", 32);
        set("con", 35);
        set("unique", 1);

        set("no_get", "÷����������̫���ˡ�\n");
        set("max_qi",3500);
        set("qi",3500);
        set("max_jing",1000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1000000);

        set_skill("claw", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("leg", 200);
        set_skill("jiuyin-baiguzhua", 200);
        set_skill("bihai-chaosheng", 200);
        set_skill("suibo-zhuliu", 200);
        set_skill("xuanfeng-tui", 200);

        map_skill("force", "bihai-chaosheng");
        map_skill("parry", "jiuyin-baiguzhua");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("claw", "jiuyin-baiguzhua");
        map_skill("leg", "xuanfeng-tui");
        prepare_skill("claw", "jiuyin-baiguzhua");

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
		"��ʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
		"��а":     "������ʦ���Ĵºš�",
		"����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
		"�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
		"��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
		"���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
		"����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
		"����":     "�ߣ��������С�Ӱ�������ʦ�磬�Ҿ�����Ź�����",
		"�":     "�������ҵ�ͽ�ܣ��������ô��",
		"÷����":   "��������ô�����ǰ׳հ���",
		"������":   "�����ҵ�ʦ�磬Ҳ���ҵķ������ϧ��������С�������ˡ�",
		"��ҩʦ":   "������ʦ����"
	]) );
        setup();
}

void die()
{
	object ob = this_object(),me,cor;

	if (!ob->query_temp("target")){
		call_out("do_die",1,ob);
		return;
	}
        
	me = query_temp("last_damage_from");

	if (me->query("id") != ob->query_temp("target")) {
		ob->revive(1);
		command("say �ã���Ȼ����" + me->name(1) + "���㣬�ߣ�");
		message_vision(HIY"÷��������Ʋ��ã�ת�����ˣ�\n"NOR, me);
		destruct(ob);
		return;
	}
	else {
		if (me->query_temp("thd/onquest") > 2
		&& me->query_temp("thd/onquest") < 4) {
			ob->revive(1);
			ob->reicarnate();
			message_vision(HIY"÷��������д�����������������ݺݵĵ���$N��\n"NOR, me);
			if (objectp(cor = present("corpse",environment(ob)))) {
				tell_room(environment(ob),"÷���罫�������ʬ������������ڱ��ϡ�\n");
				call_out("do_dest",1,cor);
			}
			command("stare");
			command("say �ߣ����������ƣ�");
			message_vision(HIY"÷���籧��������ʬ��һ���۾Ͳ����ˡ�\n\n\n"NOR, me);
			if (me->query("thd/quest1") < 1 && random(me->query_kar()/10) > 0) {
				message_vision(HIW"$N��;�����ֺͺڷ�˫ɲ������ã���������һЩ��\n"NOR,me);
				me->set("thd/quest1",1);
			}
			me->set_temp("thd/onquest",4);
		}
		else if (me->query_temp("thd/onquest") > 5
			&& me->query_temp("thd/onquest") < 7 ) {
			me->set_temp("thd/onquest",7); 
			message_vision(HIM"÷�������ϵ���һ����Ƥ�������ذ�ס�\n"NOR,me);
			message_vision(HIM"$N��ذ�׺�Ƥ������������\n"NOR,me);
			new(resolve_path(0, __DIR__"../obj/skin"))->move(me);
			new(resolve_path(0, __DIR__"../obj/bishou"))->move(me);
			call_out("do_die",1,ob);
			return;
		}
		call_out("do_dest",1,ob);
		return;
	}
}

void do_die(object ob)
{
        :: die();
}

void do_dest(object ob)
{
        destruct(ob);
}
