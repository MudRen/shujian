// qqren.c ��ǧ��

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "tz_job1.c"

int ask_qiubai();
string do_change();

void create()
{
        set_name("��ǧ��", ({ "qiu qianren", "qiu", "qianren", "ren"}));
        set("nickname", "����ˮ��Ư");
        set("long",
        "����������������ư�İ���-����ˮ��Ư��ǧ��\n"
        "����һ��������ͷ�����Ƹ���������ֻ���һ�Ѵ����ȡ�\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("unique", 1);
        set("shen_type", -1);

        set("str", 35);
        set("int", 30);
        set("con", 28);
        set("dex", 35);

        set("max_qi", 9500);
        set("max_jing", 6000);
        set("max_neili", 16000);
        set("eff_jingli", 7500);
        set("jiali", 100);
        set("combat_exp", 4350000);
        set("score", 40000);

set_skill("axe", 340);
set_skill("brush", 340);
set_skill("yingou-bifa", 340);
set_skill("lietian-fu", 340);
        set_skill("force", 340);
        set_skill("guiyuan-tunafa", 360);
        set_skill("dodge", 330);
        set_skill("shuishangpiao", 330);
        set_skill("strike", 370);
        set_skill("tiezhang-zhangfa", 370);
        set_skill("parry", 350);
        set_skill("literate", 180);
        set_skill("blade", 300);
        set_skill("liuye-daofa", 300);
        set_skill("tiezhang-xinfa", 200);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        map_skill("blade", "liuye-daofa");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhangdao" :),
                (: perform_action, "strike.tianlei" :),
                (: perform_action, "strike.judu" :),
                (: perform_action, "strike.heyi" :)
        }));
        set_temp("apply/armor", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/attack", 80);

        create_family("���ư�", 14, "����");

        set("inquiry", ([
                       "name" : "�Ϸ���ǡ�����ˮ��Ư����ǧ�������Ϸ�������ʲô��ô��\n",
                       "here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
                       "�Ϲٽ���" : (: ask_qiubai :),
                       "����" : (: ask_job1 :),
                       "����" : "��ȥ���߷���Ҫ�ɣ�",
                ]));
        setup();
        carry_object("/d/tiezhang/npc/obj/mayi")->wear();
	carry_object(ARMOR_D("buxue"))->wear();
}

void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_task","task");
}

void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping fam = ob->query("family");

        if ((int)ob->query("shen") >= -50000) {
                command("hehe");
                command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
                return;
        }
        if(fam["master_name"] == "�Ϲٽ���"){
                command("ah");
                command("grin" + ob->query("id"));
                command("say �Ϲٰ����������ѹ����������");
                command("say "+RANK_D->query_respect(ob)+"ԭ�����ϰ������ŵ��Ӱ���ʧ����"+RANK_D->query_self(me)+"����������Ϊͽ��");
                return;
        }
        if ((int)ob->query_skill("guiyuan-tunafa", 1) < 120) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��");
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڹ�Ԫ���ɷ��϶��µ㹦��");
                return;
        }
        if ((int)ob->query_str() < 28) {
                command("say ��ѧ�ҵ������Ʒ�������Ҫ���㹻��������");
                command("say �ڱ������棬"+RANK_D->query_respect(ob)+"�Ƿ��Ӳ��˵㣿");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
        command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
        ob->set("title", HIY"���ư��ʮ�Ĵ���������"NOR);
        ob->set("class","brigand");
}

int ask_qiubai()
{
        say("������ʦ��������ʮ�����������ȹ�����֮�����ж�ͼ����\n"
            "��ȫ���书�������ܡ���ϧʮ��ǰ�����ں�������Χ������������\n");
        return 1;
}
