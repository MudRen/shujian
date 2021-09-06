// suanming.c
#include <ansi.h>
inherit NPC;
string ask_where();
string ask_chance();

void create()
{
        set_name("�����", ({ "li banxian", "li", "banxian", "xiansheng" }) );
        set("nickname", "��������" );
        set("gender", "����" );
        set("age", 92);
        set("long", "��λ���������������һ������Ī������ӡ�\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("no_get", 1);
        set("inquiry", ([
                "name" : "���������Ϊ�������׼�����Դ�Ҷ������Ϊ����ɡ�",
                "rumors" : "Ҫ��֪��������Ļ������裬�Ǿ������������ɡ�",
                "����": (: ask_where :),
                "where": (: ask_where :),
                "����" : (: ask_chance :),
                "����" : "�ҵļ�Ǯ��������಻�٣�ֻҪһ���ƽ�"
        ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ߺ�ȵ����������㣬��Ǯ����������һ���ƽ�\n",
                "�����ߺ�ȵ������˻�Ե����֪���飬����ʮ���ƽ�\n",
                (: random_move :),
                "����ɶ���˵��������������������������Σ�\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string ask_chance()
{
    object me = this_player();
    me->set_temp("ask_chance",1);
    return "�����ǰɣ����Ϸ���ָ����......���������㣬����������Ϊ���װ���"NOR;
}

string ask_where()
{
    object me;
    string name;
    mapping quest;
    me=this_player();

    if ( !mapp(quest = me->query_temp("quest")))
        return "���������ǵģ�û���ʱ��˵����ٸ��";

    if (!me->query_temp("suanming_paid"))
        return "ʲô����˵ʲô�����������ء�\n";

    if (!stringp(name = me->query_temp("quest/name")))
        return "�⣬��Ҫ��˭����\n";

    if (!stringp(name = me->query_temp("quest/place")))
        return "��Ӵ�����˿ɲ�֪�������ء�\n";

    me->delete_temp("suanming_paid");
    return me->query_temp("quest/name")+CYN"�ǰɣ���˵���˿���������������"+name+CYN"һ����"NOR;
}


int accept_object(object who, object ob)
{
        int kar, per, max_age;
        int tc , temp;

        if (!who->query_temp("ask_chance") && ob->query("money_id") && ob->value() >= 5000)
        {
                message_vision("������������$N������һ��\n", who);
                who->set_temp("suanming_paid", 1);
                per = who->query("per");
                if (random(2)) per += random(10);
                  else per -= random(7);
                kar = who->query("kar");
                if (random(2)) kar += random(10);
                  else kar -= random(7);
                max_age = 67 + random(7) + who->query("con") - who->query("kar") - who->query("per")
                             + who->query("pur") + who->query("shen")/1000000;

                if (per > 25) {
                        write("��������������˵������" + RANK_D->query_respect(who) + "��ò���ã���ͥ������������Բ��");
                        if (random (kar) > 25) write("���˸���֮��Ҳ����\n");
                        else if (random (kar) >= 20) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (random (kar) >= 15) write("��ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                }
                else if (per >= 20) {
                        write("��������������ɤ�ӣ�˵������" + RANK_D->query_respect(who) + "��ò������֮�ʣ�");
                        if (random (kar) > 25) write("һ���󸻴�������ࡣ��\n");
                        else if (random (kar) >= 20) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (random (kar) >= 15) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                }
                else if (per >= 15) {
                        write("���������е���ǿ��˵������" + RANK_D->query_respect(who) + "��òƽƽ����Ҳ������������֮�ʣ�");
                        if (random (kar) > 25) write("ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (random (kar) >= 20) write("һ��Ҳ������ƽƽ��ֻ�������ȥ����\n");
                        else if (random (kar) >= 15) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("�����ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                }
                else {
                        write("��������������˵������" + RANK_D->query_respect(who) + "���Ųλ��ӡ�÷�����");
                        if (random (kar) > 25) write("������ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (random (kar) >= 20) write("������Щ������Ҳ�����ȥ�ˡ���\n");
                        else if (random (kar) >= 15) write("�������һ������������С�ˡ���\n");
                        else write("��õ�ù������Ѫ��֮�֣���\n");
                }
                write("����������ָһ�㣬������" + RANK_D->query_respect(who) + "������������" + chinese_number(max_age) + "�ꡣ��\n");
                return 1;
        } else {
                if (who->query_temp("ask_chance") && ob->query("money_id") && ob->value() >= 100000) {
                        write("������������˵��������˵����˵��һ�ж���˵����\n");

                        tc = who->query("combat_exp")/1000000;
                        write("��������˵��������" + RANK_D->query_respect(who) + "�����࣬��ǰÿ�������ܹ�����" + chinese_number(tc) + "�λ��ᡣ��\n");

                        if (!who->query("quest/jiuyin1/pass")) {
                                temp = tc - who->query("quest/jiuyin1/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�⿪�����澭�ϲᡣ��\n");
                        }

                        if (!who->query("quest/jiuyin2/pass")) {
                              	tc = who->query("combat_exp")/500000;
                                temp = tc - who->query("quest/jiuyin2/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�⿪�����澭�¾���\n");
                        }

                        if (!who->query("jiuyin/emeipass") && (who->query("family/family_name") == "������")) {
                                temp = tc - who->query("jiuyin/emeifail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�⿪���Ҿ����澭����\n");
                        }
                        if (!who->query("quest/qianzhu/pass") && (who->query("gender") == "Ů��" )) {
                        	      tc = who->query("combat_exp")/500000;
                                temp = tc - who->query("quest/qianzhu/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�⿪ǧ�����֡���\n");
                        }
                        
                        if (!who->query("quest/jiuyingm/pass") && (who->query("family/family_name") == "��Ĺ��")) {
                                tc = who->query("combat_exp")/500000;
                                temp = tc - who->query("jiuyin/jiuyingm/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�⿪��Ĺ�����澭����\n");
                        }

                        if (!who->query("quest/jiebai/pass")
                            && who->query("class") !="bonze"
                            && who->query("class") != "huanxi"
                            && (who->query("gender") == "����" || who->query("gender") == "Ů��")
                            && (int)who->query("shen") >= 0
                            && (int)who->query("combat_exp") >= 1000000) {
                                temp = tc - who->query("quest/jiebai/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ������ͯ��ݡ���\n");

                                temp = tc - who->query("quest/hubo/fail");
                                tc = who->query("combat_exp")/500000;
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬѧ��˫�����һ�������\n");
                        }

                        if (who->query("quest/jiebai/pass") && !who->query("double_attack")) {
                                tc = who->query("combat_exp")/500000;
                                temp = tc - who->query("quest/hubo/fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬѧ��˫�����һ�������\n");
                        }

/*                       if (!who->query("lbwb/lbwb1pass") && !who->query("lbwb/lbwb2pass")) {
                                temp = tc - who->query("lbwb/lbwb1fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ��������ѧ���貨΢������\n");

                                temp = tc - who->query("lbwb/lbwb2fail");
                                if (temp < 0) temp = 0;
                                write("��������˵������" + RANK_D->query_respect(who) + "����" + chinese_number(temp) + "�λ��ᣬ�Ӷ�����ѧ���貨΢������\n");
                        }
*/
                        if (who->query("combat_exp")<1000000) {
                                tc=0;
                        }
                        else
                        {
                                tc = who->query("combat_exp")/1000000;
                        }
                        temp = who->query("user_weapon_imbued");
                        write("��������˵������" + RANK_D->query_respect(who) + "��" + chinese_number(tc) + "�δ�����ᣬ�Ѿ�����" + chinese_number(temp) +"���ˡ���\n");

                        who->delete_temp("ask_chance");
                        return 1;
                }
        }
        return 0;
}

