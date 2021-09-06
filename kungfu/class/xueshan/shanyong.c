// shanyong.c ����
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "shan yong", "shanyong" ,"shan","yong"}));
        set("long",@LONG
����Ѫ���������¶����ӣ�����ݸߣ���ɫ�����͵ģ�����һ�������۾�
��������Щ���ˡ�
LONG
        );
        set("title", HIR "������Ѫ���������µ���" NOR);
        set("gender", "����");
	set("class", "huanxi");
        set("age", 42);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 1000);
        set("eff_jing", 400);
        set("max_jing",400);
	set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 40);
        set("combat_exp", 400000);
        set("score", 40000);
	set("unique", 1);

        set_skill("huanxi-chan", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("longxiang-boruo", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("staff", 100);
        set_skill("wushang-dali", 100);
        set_skill("parry", 100 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("������", 12, "����");
        set("class", "huanxi");

        setup();
        carry_object("/d/xueshan/npc/obj/gongde-jiasha")->wear();
        carry_object(BINGQI_D("jingangzuan"))->wield();      

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "������") {
               command("say"+ RANK_D->query_respect(ob) +
                        "���Ǳ��µ��ӣ������ﵷʲô�ң���");
                return;
        }

        if ((int)ob->query_skill("huanxi-chan", 1) < 80) {
                command("say ��ϲ���Ǹ����书֮���������ڼ������ɡ�");
                command("say"+ RANK_D->query_respect(ob) +
                        "�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
                return;
        }

        command("say �ðɣ��Ժ���ͺú��̷��ү�Ұɡ�");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "������Ѫ���ŵ���������" NOR);
}
