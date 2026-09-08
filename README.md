# 🎮 遊戲大廳（Game Lobby）

靜態前端遊戲集合，使用原生 HTML / CSS / JavaScript 實作。此專案適合作為作品集、教學示範與前端互動實驗平台，包含多款單機或 AI 對戰遊戲，支援雙語（繁體/英文）與深淺色主題，並在 localStorage 保留部分遊戲紀錄與統計。

版本與最後更新
- 最終更新：2026-09-05
- 本 README 版本：詳盡版（已移除貢獻章節）

---

目錄
- 功能總覽
- 專案結構
- 各遊戲功能詳解
  - 終極圈圈叉叉 (uttt.html)
  - 1A2B 猜數字 (1a2b.html)
  - 中國象棋 (xiangqi.html)
  - 方塊逃脫記 (escape.html)
- 通用 UI / 設定與儲存鍵名
- 測試與除錯建議
- 已知問題
- 開發與重構建議
- 授權
- 作者與聯絡

---

## 功能總覽
- 多款獨立遊戲：Ultimate Tic-Tac-Toe、1A2B、Xiangqi、Appel Escape
- 雙語界面（繁體中文 / English）與主題深/淺切換
- 手機 / 平板友好：觸控操作、虛擬按鍵
- 使用瀏覽器 API：Canvas、Web Audio (Oscillator)、localStorage
- 單檔開發風格：每個遊戲為單一 HTML 檔案（內嵌 CSS/JS），方便快速部署

---

## 專案結構（重點）
```
/ (repo root)
├─ index.html        # 遊戲大廳（入口）
├─ uttt.html         # 終極圈圈叉叉（Ultimate Tic-Tac-Toe）
├─ 1a2b.html         # 1A2B 猜數字（含塗鴉白板）
├─ xiangqi.html      # 中國象棋（含 AI）
├─ escape.html       # 方塊逃脫（平台跳躍）
├─ auth.html         # 驗證頁（受保護遊戲入口）
├─ mlbcard.html      # （檔案保留；README 不描述其內容）
└─ README.md
```

---

## 各遊戲功能詳解（完整）

### 1) 終極圈圈叉叉 — uttt.html
- 簡介  
  Ultimate Tic-Tac-Toe：9 個大格（3×3），每格內部為 3×3 小格。玩家在某小格下子會決定對手下次必須落子的大格。

- 模式  
  - PvP（兩人本機）  
  - PvE（玩家 VS AI）：Easy / Normal / Hard

- AI 詳細  
  - Easy：隨機合法著法（getRandomMove）  
  - Normal：基本攻防偵測（檢查能否直接贏 / 阻止對方贏）  
  - Hard：Minimax + Alpha-Beta，深度預設為 2（可調），包含簡單評估函數（大格控制、中心小格加權）

- 操作  
  - 點擊（或觸控）小格下子；介面會限制可下的大格

- UI 與反饋  
  - 高亮可下大格（pulse 動畫）  
  - 大格勝利會顯示 overlay（X / O）  
  - 規則與 demo 動畫可由「說明」彈窗查看

- 儲存  
  - localStorage key: `uttt_ai_stats`（格式 {wins, losses, draws}）

- 測試要點  
  - 切換 AI 難度後重設棋盤並測試 AI 反應  
  - 模擬玩家與 AI 交替勝利以驗證統計更新

- 實作重點（供開發者）  
  - Minimax 使用局部大格判斷與 global bigBoardState  
  - 評估函數應納入大格控制與小格權重（例如中心格權重更高）  
  - Alpha-Beta 剪枝能在有限深度降低計算量

---

### 2) 1A2B 猜數字 — 1a2b.html
- 簡介  
  Bulls & Cows（1A2B）：猜不重複的 3 或 4 位數字，系統回傳 A（數字與位置皆正確）與 B（數字正確但位置錯誤）。

- 功能  
  - 支援 3 / 4 位數切換  
  - 輸入驗證：數字、長度、是否含重複數字（輸入欄位限制為數字）  
  - 顯示猜測歷史與 A/B 回饋  
  - 成功時顯示勝利 modal，展示嘗試次數

- 白板（Canvas）工具  
  - 畫筆：線寬、顏色依主題（深 / 淺）變化  
  - 橡皮擦：使用 globalCompositeOperation = 'destination-out' 實現擦除  
  - 清除按鈕：一鍵清空畫布  
  - 支援滑鼠與觸控（touchstart / touchmove）事件

- 操作  
  - 輸入框 + 猜測按鈕（支援 Enter 提交）  
  - 建議使用 inputmode="numeric" 與 maxlength

- 儲存  
  - 歷史暫存在 DOM（重新整理後清空）；如需可擴充為 localStorage

- 測試要點  
  - 非數字或重複數字輸入應顯示友善提示  
  - 切換數位長度（3 ↔ 4）應重新產生答案並清空歷史

- 實作重點  
  - 使用隨機洗牌（shuffle）產生不重複答案  
  - 防止非數字或超長輸入

---

### 3) 中國象棋 — xiangqi.html
- 簡介  
  傳統 9×10 棋盤，完整棋子規則（帥/將、仕/士、相/象、傌/馬、俥/車、炮/包、兵/卒）、吃子與特殊規則（比如將帥直視）。

- 功能  
  - PvE（AI）與 PvP（本地雙人）  
  - AI：Minimax（可設定深度）搭配 evaluateBoard 評估函數  
  - 將軍檢查、將帥直視（Kings Facing）、合法走法驗證  
  - 擲硬幣動畫決定先後手  
  - 走棋提示、最後一步標示、危險移動警示（會導致被將或違規）

- 控制與交互  
  - 點選己方棋子顯示合法落子（綠點或可吃提示）  
  - 點擊格子執行移動；若為危險走法會顯示提示並阻止（或警告）  
  - 發生「將軍」時顯示醒目 Banner，可點擊關閉

- 儲存  
  - localStorage key: `chess_ai_stats`（{wins, losses, draws}）

- 測試要點  
  - 驗證馬腳、象眼、炮吃（隔子判定）等複雜走法  
  - 模擬將帥直視與違規判定  
  - 測試 AI 在不同難度下的合理性與計算耗時

- 實作重點  
  - canChessMove(from, to) 為核心：需處理阻塞、邊界、九宮限制等  
  - getAllLegalMoves 與 evaluateBoard 提供 AI 搜索基礎  
  - Minimax 深度過深會導致耗時，建議深度/剪枝/評估優化

---

### 4) 方塊逃脫記（Appel Escape） — escape.html
- 簡介  
  側滾式平台跳躍遊戲，分 Easy / Medium / Hard / Expert 四個難度層級，每級 5 關；包含平台、尖刺、致命地面與障礙。

- 操作  
  - 虛擬按鈕：左 / 右 / 跳（觸控友好）  
  - 鍵盤支援：ArrowLeft / ArrowRight / ArrowUp 或 WASD

- 特性  
  - Web Audio 合成音效（Jump、Death 等）  
  - 觸控事件防抖（preventDefault、touch-action 處理）  
  - 死亡計數與過關紀錄儲存在 localStorage  
  - 開發用 cheat mode：URL query `?key=ji32k7au4a83` 可解鎖所有關卡（僅供測試）

- 儲存  
  - localStorage keys:  
    - `appel_deaths`（int）  
    - `appel_cleared`（物件/陣列）  
    - `appel_lang`（語言偏好）

- 測試要點  
  - 模擬掉落、撞到尖刺、碰撞平台邊緣是否正確 triggerDeath  
  - 檢查觸控按鈕在 iOS / Android 與桌面的一致性

- 實作重點  
  - 物理模擬（重力、摩擦、air control）簡化但需穩定  
  - 碰撞偵測：矩形 vs 矩形，三角形（尖刺）與矩形混合偵測（isRectTriangleColliding）  
  - 關卡以 JS 物件陣列儲存，易於擴充

---

## 通用 UI / 設定與 localStorage 鍵名
- 語言切換：每頁有 i18n 物件 + `data-i18n` 屬性做動態替換  
- 主題切換：切換 body 的 class（`dark-mode` / `light-mode`），以 CSS 變數改配色  
- 主要 localStorage keys（摘要）：  
  - `uttt_ai_stats` — Ultimate Tic-Tac-Toe（{wins, losses, draws}）  
  - `chess_ai_stats` — Xiangqi AI 紀錄  
  - `appel_deaths`, `appel_cleared`, `appel_lang` — Appel Escape  
  - `mlb_card_game_v2` — MLB 抽卡（若保留該頁面，會使用此 key）

---

## 測試與除錯建議（開發者）
- 使用 DevTools → Application → Local Storage 清除並檢查狀態  
- 在 AI 路徑加入 console.log：顯示 Minimax 評分、候選走法與選擇理由，有助除錯  
- Canvas scale / DPR：在高 DPI 裝置上依賴 boundingClientRect 與 canvas.width/height 比例換算座標  
- 手機測試：Chrome DevTools device toolbar + 真機實測（觸控事件差異）  
- 性能：Minimax 深度 > 3 時，建議限制合法 move 數或設計時間截斷

---

## 已知問題 & 邊界情況
- Minimax 深度提高會大幅增加計算時間（尤其分支多時），建議使用淺深度 + 更佳評估函數或增設時間上限  
- 1A2B 的白板為臨時畫布，頁面重整或關閉會清除（如需保存可加入導出/下載功能）  
- auth.html 的密碼判定目前在前端示範（不安全），公開部署請改為後端驗證並移除硬編碼密碼

---

## 開發與重構建議（下一步）
- 把每個遊戲的 JavaScript 拆成獨立檔案（例如 `/src/js/uttt.js`），HTML 只負責載入與初始化  
- 將大量靜態資料（關卡、卡片清單）抽出成 JSON（`/data/levels.json`）方便維護  
- 引入簡易打包工具（Vite / Parcel）與本地 dev server，加速開發流程  
- 將遊戲核心邏輯抽成純函式，便於單元測試（Jest / Vitest）  
- 若需多人功能或遠端存檔，考慮新增後端 API（Node/Express / Firebase）

---

## 授權
- MIT License（如需變更，請在 repo 加上 LICENSE 檔）

---

## 作者
- HUGAR67  
  - GitHub: https://github.com/HUGAR67  
  - 聯絡：51s408@ms.mingdao.edu.tw  
  - 備註：本專案在開發過程中有使用 AI 作為輔助工具

---
