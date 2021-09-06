// By action 
inherit NPC;
#include <ansi.h>
#include <mudlib.h>
#define DJTIME "dj_buchang2009215"
#define DJTIMES "2009��2��15��"

int ask_clear_divorce();
int ask_gender();
int ask_divorce();
int ask_new_pks();
int ask_gold_tb();
int ask_tb_gold();
mixed change_gift(string gift);

void create()
{
        set_name("С����", ({"fairy"}));
        set("title",HBGRN"�������á�"NOR);
        set("long","һ���ɰ���С���飬��˵���������˿���ʵ�����ĵ�һЩԸ����\n");

        set("gender", "Ů��");
        set("attitude", "friendly");
        set("age", 18);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 30);
        set("no_quest", 1);
        set("combat_exp", 100000);
        set("inquiry", ([


                    "������Ե" : (: ask_clear_divorce :),
                    "�ָ��Ա�" : (: ask_gender :),
                    "���"     : (: ask_divorce :),
                    "ʮ����" : (: ask_new_pks :),
                    "�һ�ͨ��" : (: ask_gold_tb :),
                    "�һ��ƽ�" : (: ask_tb_gold :),
        ]));
        carry_object("/clone/misc/cloth")->wear();
        setup();
}


int ask_clear_divorce()
{
        int exp;
        object me = this_player();
        if (!me->query("divorce"))
        {
                command("say �����û�������ɣ�\n");
                return 1;
        }
        exp = me->query("combat_exp") * me->query("divorce") * 5 / 1000;
        if (exp > 300000)
            exp = 300000;
        command("say ������������¼���㽫Ҫ���ͷ�" + chinese_number(exp) + "�㾭�顣\n");
        command("say ��ȷ��Ҫ�������¼��(yes or no)?");
        input_to("confirm_clear_divorce", 1, me, exp);
        return 1;
}

int confirm_clear_divorce(string arg, object me, int exp)
{
        if (arg != "yes")
        {
                write("��������������¼���뷨��\n");
                return 1;
        }
        command("say �ðɣ���Ȼ������ˣ��ҾͰ���������ɣ��Ժ�ǵ�Ҫרһ����\n");
        command("sigh " + me->query("id"));
        command("lover fairy");
        log_file("quest/clear_divorce", sprintf("[%s] %s�������¼%d�Σ����پ���%d��.\n",
                ctime(time())[0..15], geteuid(this_player(1)), me->query("divorce"), exp));
        me->delete("divorce");
        me->add("combat_exp", -exp);
        me->setup();
        write(HIR"����¼�����ϣ������پ���" + chinese_number(exp) + "�㡣\n"NOR);
        return 1;
}

int ask_gender()
{
        int exp;
        object me = this_player();
        if (me->query("gender") != "����")
        {
                command("say ������ʮ�ֽ�ȫ���ѵ������ӳ������⣿\n");
                return 1;
        }
        exp = me->query("combat_exp");
        if (exp < 100000)
        {
                command("say �㾭��̫���ˣ��ߵ������ɡ�\n");
                return 1;
        }
        exp = exp * 5 / 100;
        if (exp > 300000)
                exp = 300000;
        command("say �����ָ��Ա��㽫Ҫ���ͷ�" + chinese_number(exp) + "�㾭�顣\n");
        command("say ��ȷ��Ҫ�ָ��Ա���(yes or no)?");
        input_to("confirm_gender", 1, me, exp);
        return 1;
}

int confirm_gender(string arg, object me, int exp)
{
        if (arg != "yes")
        {
                write("������˻ָ��Ա���뷨��\n");
                return 1;
        }
        command("say �ðɣ���Ȼ������ˣ��ҾͰ���ָ��ɣ����ַ����Ѷ��Ƿǳ���ģ�����\n");
        command("poor fairy");
        command("sweat fairy");
        me->delete_skill("pixie-jian");
        me->set("class", me->query("class_old"));
        me->set("gender", "����");
        me->add("combat_exp", -exp);
        me->setup();
        log_file("quest/clear_divorce", sprintf("[%s] %s�ָ��Ա�Ϊ���ԣ����پ���%d��.\n",
                ctime(time())[0..15], geteuid(this_player(1)), exp));
        write(HIR"�Ա�ָ���ϣ������پ���" + chinese_number(exp) + "�㡣\n"NOR);
        return 1;
}

int ask_divorce()
{
        object me = this_player();
        string id = me->query("marry/id");
        int last_on = FINGER_D->get_last_on(id);

        if (!me->query("marry"))
        {
                command("say ��û�н�飬����ʲô��\n");
                return 1;
        }
        if (!last_on)
        {
                command("say ���" + (me->query("gender") == "����"?"����":"���") + "�أ�\n");
                return 1;
        }
        if ((time() - last_on) / 86400 < 30)
        {
                command("say ���" + (me->query("gender") == "����"?"����":"���") + "����ŵ�½�����������ðɣ�\n");
                return 1;
        }
        command("say ������������(yes or no)?");
        input_to("confirm_divorce", 1, me);
        return 1;
}

int confirm_divorce(string arg, object me)
{
        if (arg != "yes")
        {
                write("������������뷨��\n");
                return 1;
        }
        command("say �ðɣ���Ȼ������ˣ��Ҿͳ�ȫ��ɡ�\n");
        command("sigh " + me->query("id"));
        command("lover fairy");
        me->delete("marry");
        me->add("divorce", 1);
        return 1;
}

int ask_new_pks()
{
        object me = this_player();
        

        if (me->query("PKS") >= 50 )
        {
                command("say �㲻�Ѿ��Ƕ�����ô��\n");
                return 1;
        }
            if ((int)me->query_skill("jiuyin-baiguzhua",1) < 1)
        {
                command("say �㻹û�о������澭��ѧ��\n");
                command("addoil " + me->query("id"));
                return 1;
        }

            if ((int)me->query_skill("jiuyin-baiguzhua",1) > 1 )
        {
                me->add("PKS", 50);
        }
        command("say �ðɣ���ȥ������ȥ�ɡ�\n");
        command("sigh " + me->query("id"));
        return 1;
}


int ask_gold_tb()
{
        object me = this_player();  
        
        	if (!userp(me))
        {
                command("say ��Ϊ�齣��ʦû�б�Ҫ������\n");
                return 1;
        } 
        
        if ( me->query("balance") < 100000000 )
        {
                      command("say ���"HIY"�ƽ���"NOR"����һ���������Ǵ��ű��ðɡ�\n");

                return 1;
        	
        }
        if ( me->query("balance") >= 100000000 )

        {
                me->add("balance",-100000000);
                me->add("SJ_Credit",100);
        }        
        tell_object(me,HIC"\n��ɹ���"HIY"һ�򶧻ƽ�"HIC"���ת��Ϊһ�ٸ�"HBGRN+HIG"�齣ͨ��"NOR+HIC"��\n"NOR);
      return 1;
}

int ask_tb_gold()
{
        object me = this_player();  
        
        	if (!userp(me))
        {
                command("say ��Ϊ�齣��ʦû�б�Ҫ������\n");
                return 1;
        } 
        if ( me->query("combat_exp") < 10000000 )
        {
                      command("say �Բ������ʵս���鲻��10M������ʹ���������\n");
                return 1;        	
        }

        
        if ( me->query("SJ_Credit") < 100 )
        {
                      command("say ���"HBGRN+HIG"�齣ͨ��"NOR"̫���ˣ��޷��һ�"HIY"�ƽ���"NOR"��\n");
                return 1;        	
        }
         if ( me->query("balance") >= 600000000 )
{
                       command("say ���"HIY"�ƽ���"NOR"̫���ˣ���Ͳ����������\n");
                 return 1;          
}

        if ( me->query("SJ_Credit") >= 100 )
        {
                me->add("balance",100000000);
                me->add("SJ_Credit",-100);
        }        
        tell_object(me,HIC"\n��ɹ���һ�ٸ�"HBGRN+HIG"�齣ͨ��"NOR+HIC"ת��Ϊ"HIY"һ�򶧻ƽ�"HIC"��\n"NOR);
      return 1;
}
