//you.c
//xiaoyao 98.7.25

#include <ansi.h>
inherit NPC;

string send_mail();
string receive_mail();

void create()
{
        set_name("��̹֮", ({ "you tanzhi", "you" }) );
        set("title", CYN"������վ����"NOR);
        set("gender", "����" );
        set("age", 18);
        set("long",
                "�������䲻�󣬵����շ��ż��Ĺ��������棬�Ӳ������κβ��\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "��վ" : "�ǰ�... �������������վ����Ҫ������",
                "����" : (: send_mail :),
                "����" : (: receive_mail :),
                "mail" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("unarmed", 100);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

string send_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ������е��Ŷ������档\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}

