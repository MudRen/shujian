// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
inherit ROOM;
  
mapping *sign=({
    ([  "name":"����",
        "id":"sz",
        "file":"/u/beyond/suzhou/yunhe",
        "value":10000
    ]),
    ([  "name":"����",
        "id":"yz",
        "file":"/u/beyond/yangzhou/matou",
        "value":5000
    ])
});

string look_sign();
int do_go(string);
    void create()
    {
        set("short", "��ͷ");
set("long",@LONG
������Ľ�ݼҵļ��ͺ�Ѿ�߳���̫����ˮ����ͷ��ֻ����������������
һ�����糾���ͣ���ͷ�ߵ��ϴ���������߹���������Ц�Ǻǵ�ӭ����ȥ��
�۸��(sign)��
LONG 
);
set("item_desc", ([
        "sign" : (: look_sign :)
    ]));
    set("outdoor", "abc");

    setup();
}

void init()
{
    add_action("do_go", "qu");
}

string look_sign()
{
    string str="";
    int i=sizeof(sign);

    while (i--) {
        str += sign[i]["name"];
        str += "(" + sign[i]["id"] + ") ";
        str += MONEY_D->price_str(sign[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
    ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(sign);

    if (!arg) return 0;
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("����æ���أ�\n");
    while(i--) {
        if (arg == sign[i]["id"]) {
            switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
                case 0:
                    return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                case 2:
                    return notify_fail("����Ǯ��\n");
            }
            ob->start_busy(3);
            call_out("do_move", 3, ob, i);
            return 1;
        }
    }
    return notify_fail("��Ҫȥ���\n");
}
