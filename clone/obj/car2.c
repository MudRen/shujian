//Cracked by Kafei
// Carriage2: /clone/obj/car2.c ����
// Date: xbc /04/14/97

inherit ITEM;

void create()
{
        set_name("����", ({ "da che", "che", "carriage" }) );
        set_weight(3000000);
        set_max_encumbrance(5000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG

���� - 
��������ɸɾ�����������������Ĵ����ӡ�������������������ӷ�϶��͸
��������֪�������ߵ������ˡ��������һ�����壬���������š���������ǰ
�棬һ·������һ·����غ���ʲôС����

LONG
	);

                set("amount",30);
        }
        setup();
}

int is_container() { return 1; }

void init()
{	
	remove_call_out("auto_clean_up");
	call_out("auto_clean_up",60);
}

void auto_clean_up()
{
	object *inv;
	object obj;
	string dest;

	inv = all_inventory(this_object());
	if (!inv) return;
	foreach(obj in inv) {
		if(userp(obj)) {
		if(obj->query_temp("dache_dest"))
			dest = obj->query_temp("dache_dest");
		else dest = "/d/city/kedian"; 
		obj->move(dest);
		}
	}
}

/*

	set("short", "����");
	set("long", @LONG
����ɸɾ�����������������Ĵ����ӡ�������������������ӷ�϶��͸
��������֪�������ߵ������ˡ��������һ�����壬���������š���������ǰ
�棬һ·������һ·����غ���ʲôС����
LONG
	);

	set("cost", 0);
	set("invalid_startroom", 1);
	setup();
        replace_program(ROOM);
}
*/
