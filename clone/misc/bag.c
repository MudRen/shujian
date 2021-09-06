// bao.c ���

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"���"NOR, ({ "hong bao", "bao", "bag" }));
        set("long","����һ����ɫ�̽��Сֽ���ӣ�����ӡ�š������������͡���ϲ���ơ�\n"+
                   "�ȼ���������������˵س�����ϲ����������ÿ����� fang <����>\n"+  
                   "(��coin����) ��Ǯ�Ž�������ڡ�\n");
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material","paper");
        }
        setup();
}

void init()
{
        add_action("do_open","open");
        add_action("do_fang","fang");
        add_action("do_open","dakai");        
}

int do_open(string arg)
{
       object me, obj;
       int amount;
       me = this_player();
       obj= this_object();
       amount = obj->query("balance");
       if( !arg || arg != "bag") return notify_fail("��Ҫ��ʲô?\n");
       if( me->is_fighting()) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
       if( !obj->query("finish")) return notify_fail("����û��Ǯ����\n");
       if( obj->query("owner") == me->query("id"))
              return notify_fail("�Լ����Լ����?\n");
       me->add("balance", amount) ;
       message_vision(HIY"$N�����Ĵ򿪺��......�ۣ�����\n"NOR,me);
       tell_object(me,HIW"\n���յ�"+obj->query("finish")+"("+capitalize(obj->query("owner"))+")����ĺ�������д��������"+chinese_number(amount/10000)+"���ƽ�\n\n"NOR);
        write_file("/log/quest/hongbao",sprintf("%s %s(%s)�õ�%s(%s)���ĺ��%d���ƽ�\n",ctime(time())[4..19],me->name(1),capitalize(me->query("id")),obj->query("finish"),capitalize(obj->query("owner")),amount/10000));
       destruct(obj);
       return 1;
}

int do_fang(string arg)
{
       object me;
       int amount;
       me=this_player();
       if(!arg || sscanf(arg, "%d", amount) !=1) return 0;
       if( me->query("balance") < amount ) return notify_fail("��Ĵ�����\n");
       if( amount < 10000) return notify_fail("������ģ���Ҳ̫С���˰ɡ�\n");
       if( this_object()->query("balance")) return notify_fail("��������Ѿ���Ǯ�ˡ�\n");
       me->add("balance", - amount);
       tell_object(me,HIR"\n�㽫"+ chinese_number(amount/10000)+"���ƽ��������׼�����������������\n\n"NOR);
       this_object()->set("balance", amount);
       this_object()->set("finish", me->query("name"));
       this_object()->set("owner", me->query("id"));
       this_object()->set("value", 0);
       this_object()->set("long","����һ����ɫ�̽��Сֽ���ӣ�����ӡ�š������������͡���ϲ���ơ�\n"+
                                 "�ȼ���������������˵س�����ϲ��������ӡ�š�"+this_object()->query("finish")+"��ף����������\n"+
                                 "������� open bag �򿪺����\n");
       return 1;
}
