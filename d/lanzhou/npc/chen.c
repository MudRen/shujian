// By Spiderii fix bug
// chen.c
inherit NPC;
#include <ansi.h>;

void init()
{
        object me = this_player();
        if (me->query_temp("thd/onquest")==2) { 
           message_vision(HIY"$N�����ڷ�˫ɷ�����Ͷ񣬶�ʱ����ѥ�Ե�ذ��(bishou)��\n"NOR,me);
           add_action("do_chou","chou");
        }
}

void create()
{
        set_name( "������" ,({ "chen xuanfeng", "chen" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIY"ͭʬ"NOR);
        set("gender", "����");
        set("age", 35);
        set("long",
            "�����ǻ�ҩʦ�Ķ����ӣ���Ũü���ۣ���������������׳����ֻ��\n"
            "��ɫ΢΢���ơ�\n");
        set("attitude", "aggressive");
        set("str", 37);
        set("int", 32);
        set("con", 35);

        set("unique", 1);
        set("no_quest", 1);
        set("max_qi",3500);
        set("qi",3500);
        set("max_jing",1000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 800000);

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
           "ͭʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "÷����":   "�����ҵ�ʦ�ã�Ҳ���ҵ����ҡ�",
           "������":   "��������ô�����ǰ׳հ���",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void kill_ob(object me)
{
        object ob=this_object();
        command("say �����ҵľ����澭��û��ô���ף�");
        message_vision(HIY"��������$N�������У���·������ȥ��\n\n"NOR,me);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        command("out");
        ::kill_ob(me);
}

void do_dest(object ob)
{
	::die();
}

int do_chou(string arg)
{
        object me = this_player();
        object ob = this_object();
        object obj;
        string msg;
        if (!arg||arg!="bishou")
                return notify_fail("ʲô��\n");
        if (me->query_temp("thd/onquest")!=2)
                return notify_fail("ʲô��\n");         
        if(arg=="bishou"&&me->query_temp("thd/onquest")==2)
        {
                msg = HIR"$N�����ڷ�˫ɲϮ��������һ�������ذ�׺��һ���������\n";
                msg+= HIR"��������Цһ������$N��ͷ����Ѩһ����$N��һ������Ȼ���ò���\n";
                msg+= HIR"���Ķ����ϣ�\n\n"NOR;
                msg+= HIY"���������$N����������������\n\n"NOR;
                msg+= HIC"÷����ҽ�һ�����������������㹥����\n"NOR;
                        if (!objectp(obj = present("mei chaofeng",environment(me)))) {
                                call_out("do_dest",1,ob);
                                return 1;
                        }
                obj->set_temp("target",me->query("id"));
                message_vision(msg, me);
                me->set_temp("thd/onquest",3);
                ob->die();
                return 1;
         }
}

void die()
{
	object me = query_temp("last_damage_from");
	object skin;
	int i, time;
	if (!objectp(me)) return;

        i = me->query("combat_exp") - 1000000;
        i /= 1000000;
	time = time() - me->query("quest/jiuyin2/time");

	if ((me->query("quest/jiuyin2/fail") >= 3 && me->query("registered") < 3)
//        || me->query("quest/jiuyin2/fail") >= i
	|| time < 86400 ) {
		::die();
		return;
	}

	if(
             ( 
                random(me->query("kar")) >= 22
              && me->query("combat_exp", 1) > 1000000 
             && me->query("kar",1)< 31 
             &&(random(10)==2||(me->query("buyvip")&& random(8)==3 ))
)
         || me->query("quest/jiuyin2/pass")
                                                      )
           {
            skin = unew(__DIR__"../obj/jiuyin-book2");
		if(!clonep(skin)){
			::die();
			return;
		}
		message_vision(HIY"\n$N����������������һƬƤ�˳������������\n"NOR,me);
		skin->set("owner", me->query("id"));
		skin->move(me);
		if(! me->query("quest/jiuyin2/pass"))
			log_file("quest/jiuyin",sprintf("%-18sʧ��%s�κ󣬴ӳ����紦�õ������澭�¾�����%d��\n",
              			me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("quest/jiuyin2/fail")),
              			me->query("kar")), me);
		me->set("quest/jiuyin2/pass", 1);
		::die();
		return;
	}
	me->add("quest/jiuyin2/fail", 1);
        me->set("quest/jiuyin2/time", time());
        me->set("quest/jiuyin2/combat_exp", me->query("combat_exp"));
	log_file("quest/jiuyin",
		sprintf("%-18s��ӳ����紦�õ������澭�¾�ʧ��%s�Ρ�\n",
			me->name(1)+"("+capitalize(getuid(me))+")",
                        chinese_number(me->query("quest/jiuyin2/fail"))
		), me
	);
	::die();
	return;
}
