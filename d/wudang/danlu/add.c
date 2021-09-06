// add.h
#include <ansi.h>
int do_hehe(object me, object obj, object dest);
int do_add(string arg)
{
        string arg1, arg2;
        object obj, dest, *inv, obj2;
        object ob = this_player();
        object me = this_object();
        int i, amount;
        dest = present("dan lu", environment(ob));

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���У�\n");

        if(!arg || sscanf(arg, "%s in %s", arg1, arg2)!=2)
                return notify_fail("����<add ҩ���� in lu>������Ʒ�Ž���¯��\n");

        if (arg2!="lu")
                return notify_fail("����<add ҩ���� in lu>������Ʒ�Ž���¯��\n");

        if( !me->query("marks/open", 1) )
        return notify_fail("��¯�ĸ���û�д򿪡�\n");

        if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug", 1) ) // �������Ʒû��make/drug�����ԣ����ܷŽ���¯
                return notify_fail(obj->name()+"����������Ϊ��ҩ��ԭ�ϡ�\n");

        if( !dest || living(dest) )
                return notify_fail("����û������������\n");

        if(sscanf(arg1, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, ob)) )
                        return notify_fail("������û������������\n");
                if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug", 1) )
                        return notify_fail("���ֶ�������������Ϊ��ҩ��ԭ�ϡ�\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_hehe(ob, obj, dest);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if (do_hehe(ob, obj2, dest)) return 1;
                        obj2->move(ob);
                        return 0;
                }
        }

        if(arg1=="all") {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest || !(inv[i]->query("make/drug", 1)) )
                                return notify_fail("���ֶ�������������Ϊ��ҩ��ԭ�ϡ�\n");
                        do_hehe(ob, inv[i], dest);
                write("Ok.\n");
                return 1;
        }
        if(!objectp(obj = present(arg1, ob)))
                return notify_fail("������û������������\n");

        return do_hehe(ob, obj, dest);
}

int do_hehe(object ob, object obj, object dest)
{
        object me;
        me = present("dan lu", environment(ob));
        if (!wizardp(ob) && obj->query("no_drop"))
                return notify_fail(stringp(obj->query("no_drop"))?
                        obj->query("no_drop"):"���������޷��뿪�㡣\n");

        if (obj == dest) return notify_fail("����Ž�������壿\n");
        if( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        ob );
                return 1;
        }
        return 0;
}