# 🎮 遊戲大廳 Game Lobby

一個功能完整的網頁遊戲平台，提供多種經典遊戲，支援雙語界面、深淺色切換、以及完整的遊戲統計功能。

## 📋 目錄

- [功能簡介](#功能簡介)
- [遊戲列表](#遊戲列表)
- [技術棧](#技術棧)
- [快速開始](#快速開始)
- [文件結構](#文件結構)
- [功能詳解](#功能詳解)
- [已知問題](#已知問題)
- [貢獻指南](#貢獻指南)
- [統計資訊](#統計資訊)
- [常見問題 (FAQ)](#常見問題-faq)

---

## 功能簡介

### 🌐 多語言支援
- **繁體中文** (預設)
- **英文**
- 所有文字透過 `data-i18n` 屬性動態切換

### 🌙 深淺色主題
- **淺色模式** (Light Mode)：明亮背景、深色文字
- **深色模式** (Dark Mode)：深色背景、淺色文字，保護眼睛
- 使用 CSS 變數動態切換主題色彩

### 📊 遊戲統計
- 記錄所有遊戲的戰績（勝/敗/和）
- 資料儲存在瀏覽器 `localStorage`
- 支援一鍵重置統計

### 📱 響應式設計
- 完全適配手機、平板與桌面設備
- 使用 Flexbox 與 Grid 自動調整布局

---

## 遊戲列表

### 1. ❌⭕ 終極圈圈叉叉 (Ultimate Tic-Tac-Toe)

**檔案：** `uttt.html`

**規則：**
- 棋盤由 9×9 的格子組成（9 個大格子，每個包含 9 個小格子）
- 玩家在某個小格子的位置決定對手下一手**必須進入的大格子**
- 率先在大棋盤連成 3 子的玩家獲勝

**遊戲模式：**
- **雙人對戰 (PvP)：** 兩名玩家輪流操作
- **單人對戰 (PvE)：** 玩家對戰 AI
  - **入門級 (Easy)：** AI 隨機下棋
  - **進攻級 (Normal)：** AI 執行防守和進攻策略
  - **大師級 (Hard)：** AI 使用 Minimax 演算法，近乎無敵

**特色：**
- ✨ 動畫脈衝效果：標記可下棋的大格子
- 📖 內置規則說明彈窗，含動畫演示
- 🤖 強大的 Minimax AI 引擎
- 📈 完整的 AI 對戰統計

---

### 2. 🔢 1A2B 猜數字 (Bulls and Cows)

**檔案：** `1a2b.html`

**規則：**
- 電腦預設一組不重複的數字（3 位或 4 位）
- 玩家猜測，系統回饋：
  - **A：** 數字和位置都正確的個數
  - **B：** 數字正確但位置錯誤的個數
- 猜對全部數字即獲勝

**遊戲特色：**
- 🎯 支援 3 位數和 4 位數難度切換
- 🎨 內置塗鴉白板
  - **畫筆工具：** 用滑鼠或觸筆繪畫
  - **橡皮擦：** 清除特定區域
  - **清除按鈕：** 一鍵清空白板
- 📝 完整的猜測歷史紀錄
- ⏱️ 實時反饋機制

---

### 3. 🪨 中國象棋 (Xiangqi)

**檔案：** `xiangqi.html`

**規則：**
- 傳統 9×10 象棋棋盤，包含楚河漢界與九宮格
- 完整實裝帥/將、仕/士、相/象、傌/馬、俥/車、炮/包、兵/卒等棋子移動與吃子邏輯
- 包含「將帥不可照面（飛將）」違規判定與「將軍」提示

**遊戲模式：**
- **單人對戰 (PvE)：** 玩家對戰 AI
  - **初級 (Easy)：** AI 優先考慮吃子與隨機下棋
  - **高級 (Hard)：** AI 使用 Minimax 演算法搭配 Alpha-Beta 剪枝進行多步預測
- **雙人對戰 (PvP)：** 本地雙人輪流對決

**特色：**
- ⚠️ **將軍提示與可點擊隱藏：** 發生「將軍」時彈出醒目警示橫幅，點擊橫幅可立即手動關閉，不遮擋棋盤
- 💡 **走棋提示：** 選取棋子後自動亮起合法落子點與可吃子目標
- 🛡️ **防守校驗：** 自動阻止會導致自己被將軍或將帥照面的不合法走法
- 📈 完整的 AI 對戰戰績統計 (localStorage 保存)

---

### 4. ⚾ MLB 抽卡遊戲 (MLB Card Collector)

**檔案：** 外部連結  
**URL：** https://hugar67.github.io/MLBcard/

**功能：**
- 🃏 抽卡系統，包含不同稀有度卡片
- 💰 虛擬貨幣系統
- 🏆 收藏相冊管理

---

## 技術棧

### 前端框架
- **HTML5** - 語意化標籤與 SVG 網格繪製
- **CSS3** - 變數系統、Grid、Flexbox、Keyframe 動畫
- **原生 JavaScript** - 無外部依賴 (ES6+)

### 核心技術
| 技術 | 用途 |
|------|------|
| CSS 變數 (CSS Custom Properties) | 深淺色主題動態切換 |
| localStorage API | 遊戲統計資料持久化 |
| Minimax 演算法 + Alpha-Beta 剪枝 | UTTT 與象棋 AI 棋力評估 |
| SVG & CSS Animation | 象棋棋盤渲染與將軍提示動畫 |
| Grid & Flexbox | 響應式布局與彈窗適配 |

### 瀏覽器相容性
- ✅ Chrome 90+
- ✅ Firefox 88+
- ✅ Safari 14+
- ✅ Edge 90+
- ✅ 行動瀏覽器（iOS Safari、Chrome Mobile）

---

## 快速開始

### 線上遊玩

直接訪問：https://hugar67.github.io/game-lobby/

### 本地運行

1. **克隆倉庫**
   ```bash
   git clone [https://github.com/HUGAR67/game-lobby.git](https://github.com/HUGAR67/game-lobby.git)
   cd game-lobby
運行本地伺服器Bash# Python 3
python -m http.server 8000

# Python 2
python -m SimpleHTTPServer 8000

# Node.js (http-server)
npx http-server
訪問http://localhost:8000/index.html
文件結構game-lobby/
├── index.html          # 首頁選單
├── uttt.html           # 終極圈圈叉叉遊戲
├── 1a2b.html           # 1A2B 猜數字遊戲
├── xiangqi.html        # 中國象棋遊戲
├── README.md           # 專案文檔（本文件）
└── assets/             # 資源文件夾（可選）
    ├── favicon.ico
    └── styles/         # 額外 CSS（如有）
檔案說明檔案大小功能index.html~6KB遊戲大廳首頁uttt.html~36KB終極圈圈叉叉完整實裝1a2b.html~24KB1A2B 猜數字完整實裝xiangqi.html~28KB中國象棋完整實裝 (含 AI & 將軍提示)README.md-專案文檔功能詳解中國象棋 (Xiangqi)走棋與將軍檢查流程玩家/AI 選取棋子
  ↓
計算該棋子所有基礎可走位置
  ↓
模擬走棋：
  ├─ 檢查走棋後是否造成「將帥直接對視 (飛將)」？
  └─ 檢查走棋後自己是否處於「被將軍」狀態？
  ↓
過濾掉違規走法，繪製合法落子點與吃子提示
  ↓
執行走棋 → 檢查是否擊殺敵將或對手無路可走
  ↓
檢查是否將軍對手 → 若將軍則顯示可點擊隱藏的「將軍！」橫幅
  ↓
輪轉玩家 / 觸發 AI 思考
AI 評估機制Easy 級： 計算吃子價值分，隨機選擇當前得分最高的合法著法。Hard 級： 使用深度為 2 層的 Minimax 演算法 結合 Alpha-Beta 剪枝，評估盤面棋子分值與兵卒過河/車佔中路等位置加成。終極圈圈叉叉 (UTTT)遊戲邏輯初始化
  ↓
選擇遊戲模式 (PvP / PvE)
  ↓
選擇 AI 難度 (Easy / Normal / Hard)
  ↓
玩家下棋
  ↓
檢查：
  ├─ 該大格子是否已決出勝負？
  ├─ 該大格子是否已滿？
  └─ 整個棋盤是否已決出勝負？
  ↓
更新可下棋的大格子
  ↓
輪轉玩家
  ↓
[重複]
AI 引擎Easy 級： getRandomMove() - 隨機選擇合法著法Normal 級： getTacticalMove() - 優先考慮進攻和防守Hard 級： getBestMinimaxMove() - Minimax 搜索樹，深度 2-3 層Minimax 演算法核心：JavaScriptminimax(depth, isMax, alpha, beta, targetBoard)
  如果 AI 贏了：返回高分 (1000 + depth)
  如果玩家贏了：返回低分 (-1000 - depth)
  如果深度 = 0：返回評估值
  
  對每個可能著法：
    遞迴呼叫 minimax()
    使用 Alpha-Beta 剪枝優化
  
  返回最佳著法的評估值
統計系統JavaScript// localStorage 中的格式
{
  wins: 5,      // 玩家勝場數
  losses: 2,    // 玩家敗場數
  draws: 1      // 平局次數
}
1A2B 猜數字遊戲流程初始化
  ↓
電腦隨機生成 3/4 位不重複數字
  ↓
玩家輸入猜測
  ↓
驗證輸入
  ├─ 長度是否正確？
  ├─ 是否全為數字？
  └─ 是否有重複數字？
  ↓
計算 A、B 的值
  ↓
將結果加入歷史紀錄
  ↓
檢查是否獲勝 (4A 或 3A)
  ↓
[重複或遊戲結束]
數字生成算法JavaScriptfunction generateSecret(digits) {
  let secret = [];
  while (secret.length < digits) {
    let num = Math.floor(Math.random() * 10);
    if (!secret.includes(num)) {
      secret.push(num);
    }
  }
  return secret;
}
白板功能畫筆模式
  ↓
監聽 mousedown / touchstart
  ↓
記錄座標 → 繪製線條 → 不斷更新
  ↓
監聽 mouseup / touchend
  ↓
停止繪製

橡皮擦模式
  ↓
使用 clearRect() 清除指定區域
  ↓
效果同上
已知問題🐛 當前問題1. UTTT 首次加載棋盤黑屏症狀： 從首頁點進終極圈圈叉叉時，棋盤顯示為全黑，但按「重來」後恢復正常可能原因：[ ] Dark mode 被應用但大格子未初始化[ ] CSS 變數在 JavaScript 執行前未完全載入[ ] 棋盤 DOM 元素延遲渲染暫時解決方案： 按「重來」按鈕重新初始化待修復方案：在 HTML 加載完成後延遲執行 resetUTTT()確保 CSS 變數在 JavaScript 前完全載入使用 requestAnimationFrame 確保渲染完成貢獻指南回報 Bug如發現問題，請提供：問題描述 - 清楚說明發生了什麼重現步驟 - 逐步說明如何觸發預期行為 - 應該發生什麼實際行為 - 實際發生了什麼截圖/影片 - 若可能系統資訊 - 瀏覽器、OS、裝置提交改進建議遊戲玩法改進UI/UX 優化新遊戲創意翻譯改進代碼規範使用 4 空格縮進保持變數命名清晰（camelCase）添加必要的註解確保相容性統計資訊指標數值總遊戲數3 款完整實裝遊戲 + 1 外部連結程式碼行數~2800+CSS 變數10+i18n 鍵值70+瀏覽器相容性5+ 主流瀏覽器常見問題 (FAQ)Q1: 如何重置遊戲統計？A: 在終極圈圈叉叉或中國象棋頁面，點擊對應戰績區域中的「重置」按鈕即可。Q2: 白板繪畫的筆跡在哪裡保存？A: 白板是臨時的，頁面重新整理或關閉後自動清除。若要保存，需自行截圖。Q3: 支援離線遊玩嗎？A: 是的！除了外部連結的 MLB 抽卡遊戲外，所有內置遊戲都在本地執行，無需連網。Q4: 手機上能順暢遊玩嗎？A: 完全支援！所有遊戲都經過響應式設計與觸控優化。Q5: AI 會作弊嗎？A: 絕不會！AI 完全按照規則下棋，使用 Minimax 演算法評估最佳著法。授權MIT License - 自由使用、修改和分發作者HUGAR67GitHub: https://github.com/HUGAR67專案連結: https://github.com/HUGAR67/game-lobby
