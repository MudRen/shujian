// qi-changfa.c
// Modify By River 2000/03/03
//��Դ�Ѿ��仯 ���ﲻ����Ҫ
//npc �����޸� 
//by tangfeng for ���Ǿ�quest
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "suanming xiansheng", "xiansheng", "suanming"}) );
        set("title", HIY"����"NOR);
        set("gender", "����" );
        set("age", 45);
        set("long", "��λ����վ�����һ������Ī������ӡ�\n");
        set("combat_exp", 80000);
        set("unique", 1);
        set("attitude", "friendly");
        set("inquiry", ([                 
                "rumors" : "Ҫ��֪��������Ļ������裬�Ǿ������������ɡ�",
                "����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
                "jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
                "����" : "�ҵļ�Ǯ��������಻�٣�ֻҪ��ʮ�����ӡ�"
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
                "��������ߺ�ȵ����������㣬��Ǯ���������ʶ�ʮ��������\n",
                (: random_move :),
                "������������˵��������������������������Σ�\n",
        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

int accept_object(object who, object ob)
{
        int kar, per;

        if (ob->query("money_id") && ob->value() >= 2000) 
        {
                message_vision("������������$N������һ��\n", who);
                per = who->query("per");
                kar = who->query("kar");
                if (per > 25) {
                        write("��������������˵������" + RANK_D->query_respect(who) + "��ò���ã���ͥ������������Բ��"); 
                        if (kar > 20) write("���˸���֮��Ҳ����\n");
                        else if (kar >= 17) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("��ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else if (per >= 20) {
                        write("��������������ɤ�ӣ�˵������" + RANK_D->query_respect(who) + "��ò������֮�ʣ�"); 
                        if (kar > 20) write("һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else if (per >= 15) {
                        write("���������е���ǿ��˵������" + RANK_D->query_respect(who) + "��òƽƽ����Ҳ������������֮�ʣ�");
                        if (kar > 20) write("ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("һ��Ҳ������ƽƽ��ֻ�������ȥ����\n");
                        else if (kar >= 13) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("�����ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else {
                        write("��������������˵������" + RANK_D->query_respect(who) + "���Ųλ��ӡ�÷�����");
                        if (kar > 20) write("������ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("������Щ������Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("�������һ������������С�ˡ���\n");
                        else write("��õ�ù������Ѫ��֮�֣���\n");
                        return 1;
                }
        }
        return 0;
}

