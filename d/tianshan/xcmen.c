// Room: /d/tianshan/xcmen.c
// By Linux

inherit ROOM;
int do_drop(object me, object obj);

void create()
{
	set("short", "�ɳ���");
	set("long", @LONG
�������ɳ��ţ��ɳ������滷���������޼ʣ����������ӹ���ߣ���
���������Ƽ����ݷ�����������������֮����
LONG);
	 set("exits", ([
                "northup" : __DIR__"shanjin1",
        ]));         
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
        add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_jump(string arg)
{
        object me=this_player();
        object *inv;
        int i;

        if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");
        if (arg == "down") { 
                message_vision( "$Nһ���������������¡�\n",me);
                me->move(__DIR__"yadi");
                me->set_temp("last_damage_from", "��������ˤ");
                me->unconcious();
                me->die();
                return 1;
        }
        if( (!arg) || !((arg == "duimian") || (arg == "����")))
                return notify_fail("��Ҫ��������ȥ��ɽ����\n");

        inv = filter_array(deep_inventory(me), (: userp :));
        if (sizeof(inv)) {
                message_vision("$Nһ����������������ɽ��ϣ�����һ��ʧ��......\n", me);
                me->unconcious();
                return 1;
        }

        if( (int)me->query_skill("dodge", 1) < 30 )
                return notify_fail("������Լ����Ṧ̫�����ȥ����������\n");
        
        message_vision("\n$N������˼�������ǰ����Խ�˼��������������µ��������ƣ����ڰ�գ���\n"
			"��һ�ǣ����μ�����׹,���ڿ������ɵ�һ���������Ѿ����ڶ���İ��ɽ��ϡ�\n\n",me);
        inv = deep_inventory(me);
        i= random(sizeof(inv));
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 80) {
                do_drop(me, inv[i]);
        }
	me->add_busy(2);
        me->move(__DIR__"bzhanjian");
        tell_room(environment(me), me->name() + "�Ӷ���İ��ɽ����˹�����\n",me);
        return 1;
}

int do_drop(object me, object obj)
{
        mixed no_drop;
        if( no_drop = obj->query("no_drop")) return 1;
        if( obj->is_character())
                return 1;
        else {
                message_vision( sprintf("����$N�����������ȣ����ϵ�һ%s$n������ɽ������Ҳ�Ҳ������ˡ�\n", obj->query("unit")),me, obj );
                destruct(obj);
        }
        return 1;
}
