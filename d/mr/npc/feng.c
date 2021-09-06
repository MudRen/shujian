// /u/mr/npc/feng.c �粨��
// this is made by beyond
// modify by leontt 2000/10/26
// Modify by Lklv 2001.9.20

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_yan();

void create()
{
        set_name("�粨��",({"feng boe","feng","boe"}));
        set("title","��˪ׯׯ��");
        set("nickname","һ���");
        set("long",
              "�����ǹ���Ľ����˪ׯ��ׯ����\n");
        set("age", 25);
        set("attitude", "heroism");
        set("unique", 1);
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2500);
        set("eff_jingli", 2000);
        set("max_neili", 2500);
        set("jiali", 100);
        set("combat_exp", 850000);
        set("yan", 3);
        set("score", 85000);

        set_skill("strike",130);
        set_skill("dodge",130);
        set_skill("force", 130);
        set_skill("shenyuan-gong", 130);
        set_skill("yanling-shenfa", 130);
        set_skill("parry", 130);
        set_skill("xingyi-zhang", 130);
        set_skill("literate", 130);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("strike", "xingyi-zhang");
        prepare_skill("strike", "xingyi-zhang");

        setup();

        carry_object(__DIR__"obj/cloth2")->wear();

        create_family("����Ľ��",3,"����");
	set("inquiry", ([
		"name" : "�Ҿ��ǹ���Ľ����˪ׯׯ���粨��\n",
		"here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
		"rumors" : "Ľ�ݹ��ӵġ��Ա�֮������ʩ��������������\n",
		"����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
		"����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
		"������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
		"�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
		"����Ǭ" : "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����\n",
		"����ͬ" : "����ͬ�������磬����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
		"����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
		"����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
		"��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
		"��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",
		"����" : (: ask_yan :),
		"feiyan" : (: ask_yan :),
	]));
	set("chat_chance", 2);
	set("chat_msg",({
		"�粨����������̹������������޲�֪�������������ҿ����۽硣��\n",
		"�粨�������Ҫ���ǹ��ӵ���¶����ɢ�����Ů��������������û�ˡ���\n",
	}));
}

void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title","����Ľ�ݵ��Ĵ�����");
}

string ask_yan()
{
        object ob = this_player(),obj;

        if (ob->query("family/family_name") != "����Ľ��")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query("combat_exp") < 300000)
                return RANK_D->query_respect(ob) + "����̫�����Ҳ���˷ѣ��������������˰ɡ�";

        if (this_player()->query("max_neili") < 800)
                return RANK_D->query_respect(ob) + "��������������ʱ�������ɡ�";

        if (present("fei yan", ob))
                return RANK_D->query_respect(ob) + "���������ϲ���������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (ob->query_temp("mr/feiyan") > 0)
                return RANK_D->query_respect(ob) + "��ո�Ҫ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("yan") < 1) return "�Բ��𣬷����Ѿ������ˡ�";

        obj = new("/clone/weapon/feiyan");
        obj->move(ob);
        ob->set_temp("mr/feiyan", 1);
        add("yan", -1);

        call_out("delete_yan", 30, ob);

        message_vision("$N�õ�һ�����ࡣ\n", ob);
        return "�ðɣ��������Ľ����ô���ģ����������͸���ɡ�";
}

void delete_yan(object me)
{
        if ( objectp(me) ) me->delete_temp("mr/feiyan");
}
