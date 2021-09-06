// drop.c
// Modified by snowman@SJ 16/06/2001

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj, *inv, obj2;
        int i, amount;
        string item;

        if (me->is_busy()) return notify_fail("����æ���ء�\n");

        if(!arg) return notify_fail("��Ҫ����ʲô������\n");

        if(sscanf(arg, "%d %s", amount, item)==2) {
                if (!objectp(obj = present(item, me)))
                        return notify_fail("������û������������\n");
                if (stringp(obj->query("no_drop")))
                        return notify_fail(obj->query("no_drop"));
                if (!wizardp(me) && obj->query("embedded"))
                        return notify_fail("������������ò�������\n");
                if (!obj->query_amount())
                        return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
                if (amount < 1)
                        return notify_fail("����������������һ����\n");
                if (amount > obj->query_amount())
                        return notify_fail("��û����ô���" + obj->name() + "��\n");

                else if( amount == (int)obj->query_amount() )
                        return do_drop(me, obj);
                else {
                        obj->add_amount(-amount);
                        if (obj->query("unique") && userp(me)) {
                                write(obj->name()+"���ʱһ������Ȼʧȥ����Ӱ��\n");
                                return 1;
                        }
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        obj2->set("broken", obj->query("broken"));
                        if (do_drop(me, obj2)) return 1;
                        obj2->move(me);
                        return 0;
                }
        }

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        do_drop(me, inv[i]);
                return 1;
        }

        if(!objectp(obj = present(arg, me)))
                return notify_fail("������û������������\n");

        return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
        mixed no_drop;

        if (me->is_exert() && obj == me->query_temp("weapon"))
                return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
        if (me->is_perform() && obj == me->query_temp("weapon"))
                return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

        if (obj->query("invisible") && !wizardp(me)) return 0;
        if (no_drop = obj->query("no_drop") && !wizardp(me))
                return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
        if (sizeof(all_inventory(environment(me))) > 49 )
                return notify_fail("�����Ѿ���ô�ණ���ˣ�������\n");
        
        if (obj->move(environment(me))) {
                if (me->is_fighting()) me->start_busy(1);
                if( obj->is_character() )
                        message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
                else {
                        message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),me, obj );
                        if ((!obj->query("value") && !obj->value()) ) {
                                write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
                                destruct(obj);
                        }
                        else if (( obj->query("unique") )&& userp(me)) {
                                write(obj->name()+"���ʱһ������Ȼʧȥ����Ӱ��\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
        );
        return 1;
}
