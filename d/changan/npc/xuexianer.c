// Write By Yanyang@SJ 2001.9.27
// npc: /d/changan/npc/xuexianer.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("ѩ�ɶ�", ({ "xue xianer", "xianer", "xue" }) );
        set("gender", "Ů��" );
        set("title", HIM"�����һ�"NOR);
        set("age", 36);
        set("long",
            "��ԭ��һ����¥���ˣ�����������һλ��ٿ��У���˵�����ԺҲ���Ǹ���Ա\n"
            "Ϊ�����ġ�ѩ�ɶ��ѵ����꣬���Է����̴档\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 30);
        set("shen_type", 1);
        set("no_get","ѩ�ɶ������̫���ˡ�\n");


        set("combat_exp", 2000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");

        setup();

        carry_object(ARMOR_D("flower_shoe"))->wear();
        carry_object(ARMOR_D("pink_cloth"))->wear();
}
void init()
{
        object ob;

        ::init();
	if (base_name(environment()) != query("startroom")) return;
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object me)
{
        if (!me)
                return;
        command("look " + me->query("id"));

        if (me->query("gender")=="����") {
        command("@@ "+ me->query("id"));
        command("say �ҵ��찡�����ȥ���ȥ��������Ϊ������������Ĺ����أ����㳤�ġ���");
        message("vision", me->name() +"����������¥��\n",
                environment(me), ({me}));
        me->move("/d/changan/eastjie1");
        message("vision", me->name() +"���˴����¥����˳�����\n",
                environment(me), ({me}));

        }
        else {
                if (me->query("class") =="bonze") {
                command("say �ҵ��찡��" + RANK_D->query_respect(me)
                        +"Ҳ������������¥������ӭ��ӭ������������");
                }
                if (me->query("gender")=="Ů��") {
                command("say �ҵ��찡�������´����Ҳ��Ҥ�ӣ����������������¥����");
                command("tsk");
                }
        }
        return ;
}
