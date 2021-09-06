// Npc: wuming-laoseng
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_wx();
string ask_wj();
mixed ask_ff();

void create()
{
        set_name("������ʦ", ({"wuxiang chanshi", "wuxiang", "chanshi",
        }));
        set("long",
                "����һλ�����۵Ŀ���ɮ�ˣ���ľ��ݡ�\n"
                "�뷢��Ȼȫ�ף�Ҳ������������͡�\n"
        );


        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
        set("no_bark",1);

        set("age", 80);
        set("shen", 32000);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
        set("max_jing", 7000);
        set("eff_jingli", 4000);
        set("neili", 25000);
        set("max_neili", 25000);
        set("jiali", 100);
        set("combat_exp", 6000000);

        set_skill("force", 300);
        set_skill("yijin-jing", 300);
        set_skill("dodge", 300);
        set_skill("shaolin-shenfa", 300);
        set_skill("parry", 300);
        set_skill("finger", 300);
        set_skill("buddhism", 200);
        set_skill("literate", 200);
	set_skill("wuxiang-zhi",300);
	set_skill("cuff",300);
	set_skill("luohan-quan",300);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "wuxiang-zhi");
	map_skill("cuff","luohan-quan");

        prepare_skill("finger", "wuxiang-zhi");
	prepare_skill("cuff", "luohan-quan");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qiankun" :),
        }));

        create_family("������", 34, "����");
	set("inquiry", ([
		"�����似": (: ask_wj :),
		"�����ָ": (: ask_wx :),
		"��": (: ask_ff :),
	]));

        setup();
        set_temp("apply/damage", 50);
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 60);
	UPDATE_D->get_cloth(this_object());
	set("no_quest", 1);
}

void attempt_apprentice(object ob)
{
	command("say �Բ����������ڲ���ͽ��");
	return;
}

string ask_wj()
{
	object me=this_player();

	if(me->query("wxz/quest") < 4) return 0;
	if( me->query("wxz/quest")== 4 )
		me->set("wxz/quest",5);
	return RANK_D->query_respect(me)+"�ο�̰����ѧС������֪�ȱ�Ϊ���������޳�������\n"
		+"������Ȼ�����������Ҳ��������Ե�������������ָ���㴫�˸���ɡ�\n";
}

string ask_wx()
{
	object me=this_player();

	if(me->query("wxz/done"))
		return RANK_D->query_respect(me)+"�����Ѿ�ѧ����ô��\n";

	if(me->query("wxz/quest")<5)
		return "";
	if( me->query("wxz/quest")== 5 )
		me->set("wxz/done",1);
	log_file("quest/wuxiang", sprintf("%8s%-10s ��������ʦ��ѧ�������ָ��\n",
		me->query("name"), "("+me->query("id")+")" ), me);
	command("say ����Գ�����ָ���ľ����������ϵ�ľм����������ĵá�");
	return "ֻ��ľƬԾ�����������ࡣ����Ҫ������ʵ�������������࣬�������֮����Ҳ�����гɡ�";
}

mixed ask_ff()
{
	object me=this_player();

	if (!me->query("potential")) return "���Ǳ�ܲ����ˡ�";
	if (!me->query("wxz/poison")) return RANK_D->query_respect(me)+"�𷨾���Ļ��ȱ�����Ŀǰʵ��û��ʲô���Խ���ġ�";

	do if (me->add("wxz/poison",-2-random(2)) < 0) {
		me->set("wxz/poison",0);
		break;
	}
	while (me->add("potential",-4-random(2)) > 0);
	if (me->query("potential") < 0) me->set("potential",0);
	command("say ���ļ��𣬼����ģ�����ʶ��ʶ�����ģ����ķǷ������ġ���");
	command("buddhi wuxiang chanshi");
	tell_object(me,"��������ã���������\n");
	return 1;
}
