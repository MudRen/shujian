// Write by look
// Modify by bbb
// Modify by snowman@SJ 17/02/2000
// check leitaiuser.
//�޸� by hongba
#include <ansi.h>
#include <login.h>
#define SYNTAX  "ָ���ʽ��xhw <ĳ��> because <ԭ��> \n"

inherit F_CLEAN_UP;


int main(object me, string str)
{
        object ob, where;
        int times;
        string name, reason;
        mapping note;
        
        if(!str || sscanf(str, "%s because %s", name, reason)!=2 )
                  return notify_fail(SYNTAX);

        if (!objectp(ob = LOGIN_D->find_body(name)))
                  return notify_fail("���...���... ���������?\n");


        if (wiz_level(ob))
                  return notify_fail("�Է��ǹ�ͬ�ܶ���ս���ޣ�����������̫�ðɣ�\n");

        if (!objectp(where = environment(ob)))
                  return notify_fail("����˲�֪����������Ү... :-( \n");

        if (file_name(where) == RELAX_ROOM)
                  return notify_fail("���Ѿ����һ�Դ˼���ˣ�������ץ�ˡ�\n");

        if (base_name(ob) == "/cmds/leitai/leitaiuser")
                return notify_fail(ob->name() + "�����Ǳ�����̨Clone�����ģ�����̨�������뿪�����ˡ�\n");

        
        tell_object(ob, "����Ϊ��" + reason + "�ݣ���ʱ���뵽С���ݺȲ衣\n"
        );

        message("channel", HIC "\n�����ɡ�"+ob->query("name")
                +"("+capitalize(ob->query("id"))
                +")��Ϊ��" + reason + "�ݣ���Ҫ���ܵ��飬�����뵽"
                "С���ݺȲ衣\n\n" NOR, users()
        );
        
ob->move("d/wizard/xhw");

        tell_object(me, "���"+ob->query("name")+"ץ����С���ݡ�\n");
        
        
        return 1;
}

string query(string arg)
{
        if(arg=="id") //return now_id;
        return "Wizard";
}


int help(object me)
{
write(@HELP
ָ���ʽ : xhw <ĳ��> because <ԭ��> 
��ָ������㽫ĳ��Υ�������������͵�С���ݡ�
�ȴ�������������������ϴ�󷽿ɷų���
HELP
    );
    return 1;
}

