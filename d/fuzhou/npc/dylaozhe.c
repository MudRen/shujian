// dylaozhe.c ��������
// By Looklove for a quest at 2k/5/17

#include <ansi.h>
inherit NPC;
int ask_yulou();
int ask_yugan();

void create()
{
        set_name("����", ({"lao zhe", "laozhe", "lao", "man"}));
        set("gender", "����");
        set("age", 54);
        set("str", 22);
        set("int", 20);
        set("dex", 18);
        set("con", 20);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 1100);
        set("max_jing", 1100);
        set("shen", 1000);
        set("no_get", 1);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("startroom","/d/fuzhou/island3");
        set("chat_chance", 30);
        set("chat_msg", ({
		"������������������С�����Ǹ��õط���\n",
		"����˵�������챾������ȥ���㣬û�뵽������¨������ͣ��������Ϻ�Ϳ�ˡ�\n",
		(: random_move :),
		"��������������������Ҽ����ϸ���һ���һ�ѣ������ǿ����ҵĵ���ˮ׼��\n",
		"����˵�����������϶����£���Ͳ�֪�����ҷ���ʲô�ط��ˡ�\n",
		(: random_move :)

        }));

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        set("inquiry", ([

                "���" : (: ask_yugan :),
                "��¨" : (: ask_yulou :),
                "����" : "������Ǹ��������Եĺð취��\n",
                "�������":"������������ڰɣ������е����¸Ľ�������ľͿ��ˡ�\n",
                "looklove":"�ٺ٣�������һ����㣿��Ҳ�밡�������Ҳ�����\n",
                "name" : "С��ͷ���и���ţ��˳�������\n",
                "here" : "�����㶼��֪����������Զ�������ĵ��㵺����\n",
                "rumors" : "��˵������˺ܲ���Ҫ�ǵ������ٺ١�����\n",
                "����" : "������Ǹ��������Եĺð취��\n",
        ]));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(FOOD_D("jiudai"));
        carry_object("/d/gb/obj/yulou");
        add_money("silver", 5);
}
int ask_yulou()
{
        object me;
        object lou;
        me = this_player();

        if ((present("yu lou",  environment(me))) || (present("yu lou",me))){
                command("angry "+me->query("id"));
                command("say ��¨����¨����С�Ӳ�����¿��¿ô��");
        	return 1;
        }
        if (!me->query_temp("ask/yulou")){
                command("pat "+me->query("id"));
                message_vision(HIY"���߸�$Nһ�����䡣\n"NOR, me);
                me->set_temp("ask/yulou",1);
                lou=new("/d/gb/obj/yulou");
                lou->move(me);
        	return 1;
        }
        else
        command("say �Ҳ��Ǹ���������Ū��ȥ�ˣ�");
        return 1;
}
int ask_yugan()
{
        object me;
        me = this_player();

        if (!me->query_temp("find/yugan")){
                command("touch "+me->query("id"));
                command("say ԭ����Ҳ�����㡣");
                command("say �ղ�����ľ��Ъ�ţ����������־Ͷ��Ƕ��ˡ�");
                me->set_temp("find/yugan",1);
                return 1;
        }
        else
        command("say ���Ǹ����������Լ�ȥ���ҡ�");
        return 1;
}