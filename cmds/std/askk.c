// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
//�޸Ĳ��ֲ��淶�Ĵ����Ա�message.c��ȷ�ж�������Ϣ��by Jpei 2010

#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;

string *msg_dunno = ({
        "$nҡҡͷ��˵����û��˵����\n",
        "$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
        "$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
        "$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
        "$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
        "$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n",
});

int main(object me, string arg)
{
        string dest, topic, msg;
        object ob;
        //mapping inquiry;
        string str;


        seteuid(getuid());
                        str=read_file("/log/NEWS");

        if( me->is_busy() )
                return notify_fail("����Ъ������˵���ɡ�\n");

        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("��Ҫ��˭ʲô�£�\n");

        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("����û������ˡ�\n");

        if( !ob->is_character() ) {
                message_vision("$N����$n��������....\n", me, ob);
                return 1;
        }

        if( !ob->query("can_speak") ) {
//����ask������ɫ��Ŀreikou 20071015
                message_vision("$N��$n�����йء�" + HIG +topic + NOR + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
                return 1;
        }

        if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
                message_vision("$N��$n�����йء�" + HIG +topic + NOR + "������Ϣ��\n", me, ob);

        if( userp(ob) ) return 1;
        if( !living(ob) ) {
                message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n", me, ob);
                return 1;
        }
        if(msg = ob->accept_ask(me, topic))
           { 
                  if (stringp(msg)) 
                  { 
                          message_vision(CYN "$N" CYN "��$n˵����" + msg + "\n" NOR, ob,me); 
                          return 1; 
                  } 
          }

        if( msg = ob->query("inquiry/" + topic) ) {
                if( stringp(msg) ) {
                         message_vision(CYN "$N" CYN "��$n˵����" + msg + "\n" NOR, ob,me); 
                        return 1;
                }
        } else {
                if(ob->query("race")=="Ұ��") {
                        message_vision("���Ǻ���Ȼ�ģ�$n����������$N�Ļ���\n",NOR, me,ob);
                        return 1;
                }
                switch(topic) {
                        case "name":
                        message_vision( CYN "$N��$n˵�����ҵ����־���$N," + RANK_D->query_respect(me)+ "��ʲô��?\n" NOR, ob,me);
                                break;
                        case "here":
                                message_vision(CYN "$n��$N˵����������" + environment(ob)->query("short") + "���������" + 

RANK_D->query_self(ob) + "Ҳ��̫�����\n" NOR, me, ob);
                                break;
                        default:
                if(topic=="news")
                        {
                        if (!str)
                        {
                        message_vision( CYN "$N��$n˵��,���ûʲô���ſ�˵..\n" NOR, ob, me);
                        }
else {
                        message_vision( CYN "$N��$n˵��,���������˵��:"+str+"" NOR, ob, me);
}
                        return 1;
                }       
                if(topic=="all")
                        {
                        message_vision( CYN "$N��$n����˵��:"+query_inquiry(ob)+"!\n" NOR, ob,me);
                        return 1;
                }
                                if (topic == ob->query("name") || ob->id(topic))
                                message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_self_rude(ob) + "ѽ��\n" NOR, me, ob);
                                else if (topic == me->query("name") || me->id(topic))
                                message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_rude(me) + "��ѽ��\n" NOR, me, ob);
                                else if (topic == ob->query("name") || ob->id(topic))
                                EMOTE_D->do_emote(ob, "name1");
else
                                        message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
                }
        }
        return 1;
}

string query_inquiry(object ob)
{
        int i=0;
        mapping inq;
        string str="", *indexs;
        
        if(mapp(inq=ob->query("inquiry")))
                {
                indexs=keys(inq);
                for(i=0;i<sizeof(indexs);i++)
                        {
                                str=indexs[i]+" "+str;
                                }
                str="�й��� "HIB+str+NOR CYN"������,�Һܸ��˸�����!";
                return str;
                }
        return "ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!";
        }

int help(object me)
{
   write( @HELP
ָ���ʽ: askk <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
Ԥ���ѯ������:
        here
        name
        news
        all
HELP
   );
   return 1;
}


